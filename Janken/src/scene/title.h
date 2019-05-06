#pragma once

#include "scene_base.h"

class TitleScene : public SceneBase
{
public:
	TitleScene(const InitData& data);
	void update() override;
	void draw() const override;

	void initialize() override;
	void exit() override;

private:
	const Font title_font_;
	const RectF start_btn_;
};