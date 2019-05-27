#include "play_ui_controller.h"

PlayUIController::PlayUIController(): question_font_(80, Typeface::Bold)
{

}

void PlayUIController::draw() const
{
	// –â‘è‚ğ•\¦
	String question = question_flg_ ? questionStr[0] : questionStr[1];
	question_font_(question).drawAt(Window::Width() / 2, Window::Height() / 6);

	// è‚ğ•`‰æ
	int index = static_cast<int>(hand_);
	handTexture[index].scaled(3.0).drawAt(Window::Width() / 2, Window::Height() / 2);
}

void PlayUIController::update(const std::pair<Constants::HandGesture, bool>& question)
{
	// –â‘è‚ÌXV
	hand_ = question.first;
	question_flg_ = question.second;
}