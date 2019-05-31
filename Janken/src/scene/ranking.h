#pragma once

#include <HamFramework/SceneManager.hpp>

#include "../ui/ranking_ui_controller.h"
#include "../store/ranking_store.h"

// forward declaration
namespace Constants
{
	enum class Scene;
	struct Score;
}

class RankingScene : public SceneManager<Constants::Scene, Constants::Score>::Scene
{
public:
	RankingScene(const InitData& data);
	void update() override;
	void draw() const override;

	void initialize();
	void exit();

private:
	RankingUIController ui_controller_;
	RankingStore ranking_;
};