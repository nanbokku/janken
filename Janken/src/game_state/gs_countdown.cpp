#include "gs_countdown.h"

#include "gs_play.h"
#include "../constants/constants.h"

GS_Countdown::GS_Countdown(Constants::Score* score) : GameStateBase(score),  stopwatch_(), count_(Constants::Play::MaxCountdown)
{
}

void GS_Countdown::initialize()
{
}

void GS_Countdown::update()
{
	if (!stopwatch_.isRunning()) {
		stopwatch_.reset();
		stopwatch_.start();
	}

	// �J�E���g�_�E��
	if (stopwatch_.ms() > 1000) {
		stopwatch_.reset();
		
		// �J�E���g�_�E���I��
		if (--count_ <= 0) {
			// GS_Play�X�e�[�g�ֈڂ�
			onStateFinishedCallback.invoke(std::make_shared<GS_Play>(score_));
			return;
		}
		
		stopwatch_.start();
	}

	ui_controller.update();
}

void GS_Countdown::draw()
{
	// �J�E���g�_�E���\��
	ui_controller.draw(count_);
}

void GS_Countdown::exit()
{
	
}