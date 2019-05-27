#include "LeapFinger.h"

#include <iostream>
#include <fstream>
#include <string.h>

using namespace Leap;

Constants::HandGesture LeapFinger::get()
{
	int countFingers = 0;
	Leap::Frame frame = controller_.frame();
	Leap::HandList hands = frame.hands();
	Leap::FingerList fingers = frame.fingers();


	for (int f = 0; f < frame.fingers().count(); f++) {
		Finger finger = frame.fingers()[f];
		if (finger.isExtended()) countFingers++;
	}

	switch (countFingers) {
	case 1:
		return Constants::HandGesture::Goo;
		break;

	case 2:
	case 3:
		return Constants::HandGesture::Choki;
		break;
	case 4:
	case 5:
	case 6:
		return Constants::HandGesture::Pa;
		break;

	default:
		return Constants::HandGesture::None;
		break;
	}

}