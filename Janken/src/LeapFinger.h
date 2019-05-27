#pragma once

#include "constants/constants.h"

class LeapFinger
{
public:
	LeapFinger() = default;
	~LeapFinger() = default;

	Constants::HandGesture get();
};