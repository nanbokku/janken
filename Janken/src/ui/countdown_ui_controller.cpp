#include "countdown_ui_controller.h"

#include <Siv3D.hpp>

#include "../audio_manager.h"
#include "../constants/constants.h"

CountdownUIController::CountdownUIController() : count_font_(200, Typeface::Bold)
{

}

void CountdownUIController::draw(const int count) const
{
	if (count != count_) {
		count_ = count;

		AudioManager::Instance().playSE(Constants::Audio::CountStr);
	}

	count_font_(int2chr32(count_)).draw(Arg::center = Vec2(Window::Width() / 2, Window::Height() / 2));
}

void CountdownUIController::update()
{

}

char32_t CountdownUIController::int2chr32(const int num) const
{
	auto str = ToString(num);
	char32_t c32 = *(str.c_str());

	return c32;
}