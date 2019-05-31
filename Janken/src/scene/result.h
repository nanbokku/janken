#pragma once

#include <HamFramework/SceneManager.hpp>

#include "../ui/result_ui_controller.h"
#include "../store/ranking_store.h"

// forward declaration
namespace Constants
{
	enum class Scene;
	struct Score;
}

class ResultScene : public SceneManager<Constants::Scene, Constants::Score>::Scene
{
public:
	ResultScene(const InitData& data);
	void update() override;
	void draw()  const override;
	void ResultScore();
	void initialize();
	void exit();

private:
	ResultUIController ui_controller_;
	RankingStore ranking_;
};