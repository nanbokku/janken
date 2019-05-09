#pragma once

#include <HamFramework/SceneManager.hpp>

#include "../constants/constants.h"

class ResultScene : public SceneManager<Constants::Scene>::Scene
{
public:
	ResultScene(const InitData& data);
	void update() override;
	void draw() const override;

	void initialize();
	void exit();
};