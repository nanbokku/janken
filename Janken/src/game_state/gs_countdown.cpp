#include "gs_countdown.h"

#include <Siv3D.hpp>

#include "../ui/title_ui_controller.h"
#include "gs_play.h"
#include "../constants/constants.h"

GS_Countdown::GS_Countdown() : GameStateBase(), ui_controller(std::make_unique<TitleUIController>()),  stopwatch_(std::make_unique<Stopwatch>()), count_(Constants::Play::MaxCountdown)
{
}

void GS_Countdown::initialize()
{
	stopwatch_->start();
}

void GS_Countdown::update()
{
	// カウントダウン
	if (stopwatch_->ms() > 1000) {
		stopwatch_->reset();
		
		// カウントダウン終了
		if (--count_ <= 0) {
			// GS_Playステートへ移る
			invokeStateFinishedCallback(std::make_shared<GS_Play>());
			return;
		}
		
		stopwatch_->start();
	}
}

void GS_Countdown::draw()
{
	// カウントダウン表示
	ui_controller->drawCountdown(count_);
}

void GS_Countdown::exit()
{
	
}