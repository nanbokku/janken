#pragma once

#include "game_state_base.h"

// forward declaration
class PlayUIController;
namespace s3d
{
	class Stopwatch;
}

class GS_Play : public GameStateBase
{
public:
	GS_Play();

	void initialize() override;
	void update() override;
	void draw() override;
	void exit() override;

private:
	std::unique_ptr<PlayUIController> ui_controller_;
	std::unique_ptr<s3d::Stopwatch> stopwatch_;
};