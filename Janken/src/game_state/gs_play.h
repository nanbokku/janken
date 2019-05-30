#pragma once

#include "game_state_base.h"

#include <Siv3D.hpp>

#include "../ui/play_ui_controller.h"
#include "../store/janken_history.h"
#include "../janken_generator.h"
#include "../event/event.h"
#include "../LeapFinger.h"

namespace Constants
{
	struct Score;
}

class GS_Play : public GameStateBase
{
public:
	GS_Play(Constants::Score*);
	Constants::HandGesture prev_hand, new_hand;
	void initialize() override;
	void update() override;
	void draw() override;
	void exit() override;

private:
	// ���̖���
	void next(bool);
	// ���̍쐬
	void newQuestion();

	PlayUIController ui_controller_;
	JankenHistory history_;
	JankenGenerator generator_;
	LeapFinger leap_;
	Stopwatch stopwatch_;
	bool is_active_;
	std::mutex mtx_;
};