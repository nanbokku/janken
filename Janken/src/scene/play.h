#pragma once

#include "scene_base.h"

// forward declaration
class GameStateBase;

class PlayScene : public SceneBase
{
public:
	PlayScene(const InitData& data);
	void update() override;
	void draw() const override;

	void initialize() override;
	void exit() override;

private:
	void changeState(const std::shared_ptr<GameStateBase>& state);
	
	std::shared_ptr<GameStateBase> current_state_;
};