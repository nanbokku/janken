#pragma once

#include <HamFramework/SceneManager.hpp>

#include "../constants/constants.h"

// forward declaration
class GameStateBase;

class PlayScene : public SceneManager<Constants::Scene>::Scene
{
public:
	PlayScene(const InitData& data);
	void update() override;
	void draw() const override;

	void initialize();
	void exit();

private:
	void changeState(const std::shared_ptr<GameStateBase>& state);
	
	std::shared_ptr<GameStateBase> current_state_;
};