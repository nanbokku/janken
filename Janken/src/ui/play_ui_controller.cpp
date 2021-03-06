#include "play_ui_controller.h"

PlayUIController::PlayUIController() : question_font_(80, Typeface::Bold)
{

}

void PlayUIController::draw() const
{
	if (show_question_) {
		// 問題を表示
		String question = question_flg_ ? questionStr[0] : questionStr[1];
		question_font_(question).drawAt(Window::Width() / 2, Window::Height() / 6);

		// 手を描画
		int index = static_cast<int>(hand_);
		handTexture[index].scaled(3.0).drawAt(Window::Width() / 2, Window::Height() / 2);
	}
	else {
		auto texture = correct_ ? correctTexture : incorrectTexture;

		texture.scaled(3.0).drawAt(Window::Width() / 2, Window::Height() / 2);
	}
}

void PlayUIController::update(const std::pair<Constants::HandGesture, bool>& question)
{
	// 問題の更新
	hand_ = question.first;
	question_flg_ = question.second;

	show_question_ = true;
}

void PlayUIController::update(const bool correct)
{
	correct_ = correct;

	show_question_ = false;
}