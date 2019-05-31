#pragma once

#include <Siv3D.hpp>
#include "../event/event.h"

class RankingUIController
{
public:
	RankingUIController();
	~RankingUIController() = default;

	void draw() const;
	void update();

	Event<void, void> onTitleBtnClickedCallback;

private:
	// 初期化のためラムダ式を定義，即使用
	const std::vector<Rect> rects_ = []() {
		std::vector<Rect> tmp;
		for (int i = 0, j = 1; i < 10; i++, j++) {
			double x, y;

			if (i >= 5) {
				x = Window::Width() / 4 * 3;
				y = Window::Height() / 7 * (j - 5);
			}
			else {
				x = Window::Width() / 4 * 1;
				y = Window::Height() / 7 * j;
			}

			Rect rect = Rect(550, 100).setCenter(x, y);

			tmp.push_back(rect);
		}
		return tmp;
	}();
	const Font font_;
	const Rect return_btn_;
};