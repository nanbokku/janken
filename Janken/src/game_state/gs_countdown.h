#pragma once

#include "game_state_base.h"

#include <Siv3D.hpp>
#include "../ui/countdown_ui_controller.h"

namespace Constants
{
	struct Score;
}

class GS_Countdown : public GameStateBase
{
public:
	GS_Countdown(Constants::Score*);

	void initialize() override;
	void update() override;
	void draw() override;
	void exit() override;

private:
	CountdownUIController ui_controller;
	s3d::Stopwatch stopwatch_;
	int count_;
};