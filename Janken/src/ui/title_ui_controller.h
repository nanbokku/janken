#pragma once

#include <Siv3D.hpp>

#include "../event/event.h"

class TitleUIController
{
public:
	TitleUIController();
	~TitleUIController() = default;

	void draw() const;
	void update();

	Event<void, void> onStartBtnClickedCallback;

private:
	const Font title_font_;
	const RectF start_btn_;
};