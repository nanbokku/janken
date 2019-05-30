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
	Vector position = hands.frontmost().palmPosition();

	for (int f = 0; f < frame.fingers().count(); f++) {
		Finger finger = frame.fingers()[f];
		if (finger.isExtended()) countFingers++;
	}
	if ((hands.isEmpty()) || !((-100 < position.x) && (position.x < 100))) {
		return Constants::HandGesture::None;
	}
	
	switch (countFingers) {
	case 0:
		return Constants::HandGesture::Goo;
	case 1:
	case 2:
		return Constants::HandGesture::Choki;
	case 3:
	case 4:
	case 5:
		return Constants::HandGesture::Pa;

	default:
		return Constants::HandGesture::None;
	}

}
