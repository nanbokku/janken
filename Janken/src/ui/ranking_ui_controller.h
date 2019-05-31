#pragma once

#include "../event/event.h"

class RankingUIController
{
public:
	RankingUIController();
	~RankingUIController() = default;

	void draw() const;
	void update();

	Event<void, void> onTitleBtnClickedCallback;


};