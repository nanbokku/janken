#include "gs_play.h"

#include "../store/janken_history.h"
#include "../scene/result.h"
#include "../constants/constants.h"

using question_pair = std::pair<Constants::HandGesture, bool>;

GS_Play::GS_Play(Constants::Score* score) : GameStateBase(score), ui_controller_(), history_(), generator_(), player_(), stopwatch_()
{
}

void GS_Play::initialize()
{
	Print << U"play state";

	// 問題が生成されたときのコールバックを登録
	history_.onQuestionAddedCallback.set([&](const question_pair& questions) {
		this->player_.setActive(true);
		this->stopwatch_.start();
		this->ui_controller_.update(questions);
	});

	player_.setActive(false);

	newQuestion();
}

void GS_Play::update()
{
	// 時間切れ
	if (stopwatch_.isRunning() && stopwatch_.ms() > Constants::Play::MaxWaitMs) {
		stopwatch_.reset();
		player_.setActive(false);

		// 次の問題へ
		next();
		return;
	}

	// TODO: LeapMotionから手を取得
	// HandGesture hand = getHand()
	// auto correct = history_.addAnswer(hand);
	// if (correct) {
		//next();
		//score_->correct_answers++;
	//}
}

void GS_Play::draw()
{
	ui_controller_.draw();
}

void GS_Play::exit()
{

}

void GS_Play::next()
{
	if (history_.getTotalNumberOfQuestions() >= Constants::Play::MaxNumOfQuestions) {
		// ステート終了
		onStateFinishedCallback.invoke(nullptr);
		return;
	}

	newQuestion();
}

void GS_Play::newQuestion()
{	
	for (hand1=hand2; hand1 == hand2;) {
		hand2 = generator_.randomHand();
	}
	auto is_winning = generator_.isWinningOrLosing();
	auto question = question_pair(hand2, is_winning);
	
	history_.push_back_question(question);

	Print << U"add question";
}