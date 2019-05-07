#include "gs_play.h"

#include <memory>
#include <Siv3D.hpp>

#include "../ui/play_ui_controller.h"

GS_Play::GS_Play() : GameStateBase(), ui_controller_(std::make_unique<PlayUIController>()), stopwatch_(std::make_unique<Stopwatch>())
{
}

void GS_Play::initialize()
{
	Print << U"play state";

	stopwatch_->start();
}

void GS_Play::update()
{
	
}

void GS_Play::draw()
{

}

void GS_Play::exit()
{

}