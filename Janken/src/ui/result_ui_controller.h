#pragma once

#include <Siv3D.hpp>

#include "../event/event.h"


class ResultUIController  
{
public:
	ResultUIController();
	~ResultUIController() = default;

	void draw() const;
	void update();
	void setInputState(bool);

	int result_score;
	Event<void, void> onStartBtnClickedCallback;
	Event<void, void> onRankingBtnClickedCallback;
	Event<void, std::string> onNameInputedCallback;

private:
	TextEditState text_;
	bool input_state_;
	int push_count_ = 0;

	const Font result_font_;
	const RectF return_btn_;
	const RectF ranking_btn_;
	const Font name_font_;
	const RectF text_back_;
};
