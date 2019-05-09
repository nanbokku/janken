#pragma once

#include <HamFramework/SceneManager.hpp>

// forward declaration
class GameStateBase;
namespace Constants
{
	enum class Scene;
	struct Score;
}

class PlayScene : public SceneManager<Constants::Scene, Constants::Score>::Scene
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