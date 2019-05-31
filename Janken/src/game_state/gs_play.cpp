#include "gs_play.h"

#include "../store/janken_history.h"
#include "../scene/result.h"
#include "../constants/constants.h"
#include "../audio_manager.h"

#define STR(var) #var

using question_pair = std::pair<Constants::HandGesture, bool>;

GS_Play::GS_Play(Constants::Score* score) : GameStateBase(score), ui_controller_(), history_(), generator_(), stopwatch_(), leap_(), is_active_(false)
{
	// 画面の初期化
	System::Update();
}

void GS_Play::initialize()
{
	// 問題が生成されたときのコールバックを登録
	history_.onQuestionAddedCallback.set([&](const question_pair& questions) {
		is_active_ = true;
		this->stopwatch_.start();
		this->ui_controller_.update(questions);
	});

	is_active_ = false;

	newQuestion();
}

void GS_Play::update()
{
	std::lock_guard<std::mutex> lock(mtx_);

	if (!is_active_) return;

	// 時間切れ
	if (stopwatch_.isRunning() && stopwatch_.ms() > Constants::Play::MaxWaitMs) {
		score_->time_score += Constants::Play::MaxWaitMs;

		// 次の問題へ
		next(false);
		return;
	}

	// LeapMotionから手を取得
	auto hand = leap_.get();
	auto correct = history_.addAnswer(hand);

	if (correct) {
		score_->time_score += stopwatch_.ms();
		score_->correct_answers++;

		next(correct);
	}
}

void GS_Play::draw()
{
	ui_controller_.draw();
}

void GS_Play::exit()
{
	// コールバック関数のunset
	history_.onQuestionAddedCallback.unset();
}

void GS_Play::next(const bool correct)
{
	stopwatch_.reset();
	is_active_ = false;

	ui_controller_.update(correct);

	auto audio_str = correct ? Constants::Audio::CorrectStr : Constants::Audio::IncorrectStr;
	double wait = AudioManager::Instance().getLengthSec(audio_str) + 0.5;
	AudioManager::Instance().playSE(audio_str);

	// コルーチン代わり
	std::thread([&](double sec) {
		std::lock_guard<std::mutex> lock(mtx_);

		// 正解/不正解の音が終了するまで待つ
		std::this_thread::sleep_for(std::chrono::duration<double>(sec));

		if (history_.getTotalNumberOfQuestions() >= Constants::Play::MaxNumOfQuestions) {
			// ステート終了
			onStateFinishedCallback.invoke(nullptr);
			return;
		}

		newQuestion();
	}, wait).detach();
}

void GS_Play::newQuestion()
{
	for (prev_hand = new_hand; prev_hand == new_hand;) {
		new_hand = generator_.randomHand();
	}
	auto is_winning = generator_.isWinningOrLosing();
	auto question = question_pair(new_hand, is_winning);

	AudioManager::Instance().playSE(Constants::Audio::JankenponStr);

	history_.push_back_question(question);
}