#pragma once

#include <HamFramework/SceneManager.hpp>

#include "../ui/title_ui_controller.h"
#include "../constants/constants.h"

class TitleScene : public SceneManager<Constants::Scene, Constants::Score>::Scene
{
public:
	TitleScene(const InitData& data);
	void update() override;
	void draw() const override;

	void initialize();
	void exit();

private:
	TitleUIController ui_controller_;
};