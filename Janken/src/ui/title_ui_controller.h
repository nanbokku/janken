#pragma once

#include <Siv3D.hpp>

class TitleUIController
{
public:
	TitleUIController();
	~TitleUIController() = default;

	void draw() const;
	void update();

	void setStartBtnClickedCallback(const std::function<void(void)>& callback)
	{
		onStartBtnClickedCallback_ = callback;
	}

private:
	inline void invokeStartBtnClickedCallback()
	{
		if (onStartBtnClickedCallback_) {
			onStartBtnClickedCallback_();
		}
	}

	std::function<void(void)> onStartBtnClickedCallback_;
	const Font title_font_;
	const RectF start_btn_;
};