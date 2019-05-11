#include "gs_countdown.h"

#include "gs_play.h"
#include "../constants/constants.h"

GS_Countdown::GS_Countdown(Constants::Score* score) : GameStateBase(score),  stopwatch_(), count_(Constants::Play::MaxCountdown)
{
}

void GS_Countdown::initialize()
{
	stopwatch_.start();
}

void GS_Countdown::update()
{
	// カウントダウン
	if (stopwatch_.ms() > 1000) {
		stopwatch_.reset();
		
		// カウントダウン終了
		if (--count_ <= 0) {
			// GS_Playステートへ移る
			onStateFinishedCallback.invoke(std::make_shared<GS_Play>(score_));
			return;
		}
		
		stopwatch_.start();
	}

	ui_controller.update();
}

void GS_Countdown::draw()
{
	// カウントダウン表示
	ui_controller.draw(count_);
}

void GS_Countdown::exit()
{
	
}