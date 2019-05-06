#pragma once

#include "game_state_base.h"

class GS_Play : public GameStateBase
{
public:
	GS_Play();

	void initialize() override;
	void update() override;
	void draw() override;
	void exit() override;
};