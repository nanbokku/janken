#pragma once

#include "../event/event.h"

class ResultUIController
{
public:
	ResultUIController();
	~ResultUIController() = default;

	void draw() const;
	void update();

	Event<void, void> onStartBtnClickedCallback;
};