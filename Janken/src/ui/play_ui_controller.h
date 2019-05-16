#pragma once

#include "../constants/constants.h"

class PlayUIController
{
public:
	PlayUIController();
	~PlayUIController() = default;

	void draw() const;
	void update(const std::pair<Constants::HandGesture, bool>&);

private:
	Constants::HandGesture hand_;
	bool question_flg_;
	
	const Font question_font_;
	const std::vector<Texture> Hand_Texture = { Texture(Emoji(U"✊")), Texture(Emoji(U"✌")), Texture(Emoji(U"✋")) };
	const std::vector<String> Question_Str = { U"勝ってください", U"負けてください" };
};