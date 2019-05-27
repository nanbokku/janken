#pragma once

#include "Leap.h"
#include "constants/constants.h"

class LeapFinger
{
public:
	LeapFinger() = default;
	~LeapFinger() = default;

	Constants::HandGesture get();

private:
	Leap::Controller controller_;
};