#pragma once

#include <Siv3D.hpp>
#include "../event/event.h"

class RankingUIController
{
public:
	RankingUIController();
	~RankingUIController() = default;

	void draw() const;
	void update();

	Event<void, void> onTitleBtnClickedCallback;

private:
	const std::vector<Rect> rects_;
	const Font font_;
};