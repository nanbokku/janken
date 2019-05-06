#pragma once

#include "game_state_base.h"

#include <Siv3D.hpp>

class GS_Countdown : public GameStateBase
{
public:
	GS_Countdown();

	void initialize() override;
	void update() override;
	void draw() override;
	void exit() override;

private:
	std::unique_ptr<Stopwatch> stopwatch_;
	int count_;
	Font count_font_;

	const std::array<String, 3> CountStr = { U"3",U"2",U"1" };
};