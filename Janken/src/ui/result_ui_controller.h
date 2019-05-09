#pragma once

#include <functional>

class ResultUIController
{
public:
	ResultUIController();
	~ResultUIController() = default;

	void draw() const;
	void update();

	void setStartBtnClickedCallback(const std::function<void(void)>& callback)
	{
		onStartBtnClicekedCallback_ = callback;
	}

private:
	inline void invokeStartBtnClickedCallback()
	{
		if (onStartBtnClicekedCallback_) {
			onStartBtnClicekedCallback_();
		}
	}

	std::function<void(void)> onStartBtnClicekedCallback_;
};