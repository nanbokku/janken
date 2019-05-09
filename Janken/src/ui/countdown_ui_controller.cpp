#include "countdown_ui_controller.h"

#include <Siv3D.hpp>

CountdownUIController::CountdownUIController() : count_font_(80, Typeface::Bold)
{

}

void CountdownUIController::draw(const int count) const
{
	count_font_(int2chr32(count)).draw(Arg::center = Vec2(Window::Width() / 2, Window::Height() / 2));
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