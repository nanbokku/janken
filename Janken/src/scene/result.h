#pragma once

#include "scene_base.h"

class ResultScene : public SceneBase
{
public:
	ResultScene(const InitData& data);
	void update() override;
	void draw() const override;

	void initialize() override;
	void exit() override;
};