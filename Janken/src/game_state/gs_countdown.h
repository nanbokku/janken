#pragma once

#include "game_state_base.h"

// forward declaration
class TitleUIController;
// forward declaration
namespace s3d
{
	class Stopwatch;
}

class GS_Countdown : public GameStateBase
{
public:
	GS_Countdown();

	void initialize() override;
	void update() override;
	void draw() override;
	void exit() override;

private:
	std::unique_ptr<TitleUIController> ui_controller;
	std::unique_ptr<s3d::Stopwatch> stopwatch_;
	int count_;
};