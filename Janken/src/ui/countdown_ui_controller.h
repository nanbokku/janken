#pragma once

#include <Siv3D/Font.hpp>

class CountdownUIController
{
public:
	CountdownUIController();
	~CountdownUIController() = default;

	void draw(int) const;
	void update();

private:
	const s3d::Font count_font_;
	mutable int count_ = -1;
	
	// int����char32_t�֕ϊ�
	char32_t int2chr32(int) const;
};