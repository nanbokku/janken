#pragma once

#include "../constants/constants.h"

class PlayUIController
{
public:
	PlayUIController() = default;
	~PlayUIController() = default;

	void draw() const;
	void update(const std::pair<Constants::HandGesture, bool>&);
};