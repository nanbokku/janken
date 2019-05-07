#pragma once

#include <Siv3D/Font.hpp>

class TitleUIController
{
public:
	TitleUIController();
	~TitleUIController() = default;

	void drawCountdown(int);

private:
	s3d::Font count_font_;
	
	// intからchar32_tへ変換
	char32_t int2chr32(int);
};