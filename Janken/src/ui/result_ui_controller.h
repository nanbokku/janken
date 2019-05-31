#pragma once

#include <Siv3D.hpp>

#include "../event/event.h"


class ResultUIController  
{
public:
	ResultUIController();
	~ResultUIController() = default;

	void draw() const;
	void update();
	int result_score;
	Event<void, void> onStartBtnClickedCallback;
	Event<void, void> onRankingBtnClickedCallback;

private:
	const Font result_font_;
	const RectF return_btn_;
	const RectF ranking_btn_;
};
