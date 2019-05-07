#include "title_ui_controller.h"

#include <Siv3D.hpp>

TitleUIController::TitleUIController() : count_font_(80, Typeface::Bold)
{

}

void TitleUIController::drawCountdown(const int count)
{
	count_font_(int2chr32(count)).draw(Arg::center = Vec2(Window::Width() / 2, Window::Height() / 2));
}

char32_t TitleUIController::int2chr32(const int num)
{
	auto str = ToString(num);
	char32_t c32 = *(str.c_str());

	return c32;
}