#include "gs_play.h"

#include "../store/janken_history.h"
#include "../scene/result.h"
#include "../constants/constants.h"
#include "../audio_manager.h"

#define STR(var) #var

using question_pair = std::pair<Constants::HandGesture, bool>;

GS_Play::GS_Play(Constants::Score* score) : GameStateBase(score), ui_controller_(), history_(), generator_(), player_(), stopwatch_(), leap_()
{
	// ��ʂ̏�����
	System::Update();
}

void GS_Play::initialize()
{
	Print << U"play state";


	// ��肪�������ꂽ�Ƃ��̃R�[���o�b�N��o�^
	history_.onQuestionAddedCallback.set([&](const question_pair& questions) {
		this->player_.setActive(true);
		this->stopwatch_.start();
		this->ui_controller_.update(questions);

		std::thread([] {
			System::Sleep(1000);
			AudioManager::Instance().playSE(Constants::Audio::PonStr);
		}).detach();
	});

	player_.setActive(false);

	newQuestion();
}

void GS_Play::update()
{
	// ���Ԑ؂�
	if (stopwatch_.isRunning() && stopwatch_.ms() > Constants::Play::MaxWaitMs) {
		stopwatch_.reset();
		player_.setActive(false);
		score_->time_score += Constants::Play::MaxWaitMs;
		// ���̖���
		next();
		return;
	}

	// LeapMotion�������擾
	auto hand = leap_.get();
	auto correct = history_.addAnswer(hand);

	if (correct) Print << U"correct";

	if (correct) {
		next();
		score_->time_score += stopwatch_.ms();
		score_->correct_answers++;
	}
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
	stopwatch_.reset();

	// ��ʏ�����
	System::Update();

	if (history_.getTotalNumberOfQuestions() >= Constants::Play::MaxNumOfQuestions) {
		// �X�e�[�g�I��
		onStateFinishedCallback.invoke(nullptr);
		return;
	}

	newQuestion();
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

	Print << U"add question";
}