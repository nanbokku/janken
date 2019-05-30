#pragma once

#include "../constants/constants.h"
#include "../event/event.h"

class PlayUIController
{
public:
	PlayUIController();
	~PlayUIController() = default;

	void draw() const;
	void update(const std::pair<Constants::HandGesture, bool>&);
	void update(bool);

private:
	Constants::HandGesture hand_;
	bool question_flg_;
	bool correct_;
	bool show_question_;
	
	const Font question_font_;
	const std::vector<Texture> handTexture = { Texture(Emoji(U"✊"), TextureDesc::Mipped), Texture(Emoji(U"✌"), TextureDesc::Mipped), Texture(Emoji(U"✋"), TextureDesc::Mipped) };
	const std::vector<String> questionStr = { U"勝ってください", U"負けてください" };
	const Texture correctTexture = Texture(Emoji(U"⭕"), TextureDesc::Mipped);
	const Texture incorrectTexture = Texture(Emoji(U"❌"), TextureDesc::Mipped);
};