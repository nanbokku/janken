#include "result_ui_controller.h"
#include "../constants/constants.h"


ResultUIController::ResultUIController() : result_font_(100, Typeface::Bold, FontStyle::Bitmap), return_btn_(SimpleGUI::ButtonRegionAt(Constants::Result::ReturnBtnStr, Constants::Result::ReturnBtnCenterPos, 300)), ranking_btn_(SimpleGUI::ButtonRegionAt(Constants::Result::RankingBtnStr, Constants::Result::RankingBtnCenterPos, 300)), text_(), text_back_(Arg::center = Vec2(Window::Width() / 2, Window::Height() / 2), Vec2(500, 300)), input_state_(false), name_font_(25, Typeface::Bold)
{

}

void ResultUIController::draw() const
{
	// ���𐔂̕\��
	result_font_(Constants::Result::ResultStr).draw(Arg::center = Constants::Result::ResultCenterPos.movedBy(1.5, 2), Constants::ShadowColor);   // �e������
	result_font_(Constants::Result::ResultStr).draw(Arg::center = Constants::Result::ResultCenterPos, Constants::Result::ResultColor);

	String score = Format(result_score);
	if (!input_state_ || push_count_ <= 0) result_font_(score).draw(Arg::center = Constants::Result::ScoreCenterPos, Constants::Result::ResultColor);

	// �^�C�g���ɖ߂�{�^���\��
	SimpleGUI::ButtonAt(Constants::Result::ReturnBtnStr, Constants::Result::ReturnBtnCenterPos, 300);

	// �����L���O�{�^��
	SimpleGUI::ButtonAt(Constants::Result::RankingBtnStr, Constants::Result::RankingBtnCenterPos, 300);
}

void ResultUIController::update()
{
	if (MouseL.down()) {
		push_count_++;
	}

	// �^�C�g���ɖ߂�{�^�����N���b�N
	if (return_btn_.leftClicked()) {
		if (input_state_) return;

		onStartBtnClickedCallback.invoke();
	}

	// �����L���O�{�^���N���b�N
	if (ranking_btn_.leftClicked()) {
		if (input_state_) return;

		onRankingBtnClickedCallback.invoke();
	}

	if (!input_state_ || push_count_ <= 0) return;

	// �ق�Ƃ�draw�ɏ�������
	text_back_.draw(ColorF(0.0, 1.0));
	name_font_(U"�����L���O�X�V�I���O����͂��ĂˁD").drawAt(Vec2(Window::Width() / 2, Window::Height() / 2 - 80));
	SimpleGUI::TextBoxAt(text_, Window::Center(), 300, 7);
	if (SimpleGUI::ButtonAt(U"����", Vec2(Window::Width()/2, Window::Height() / 2 + 100), 100)) {
		if (text_.text.isEmpty()) return;

		// ���O����͂���
		onNameInputedCallback.invoke(text_.text.toUTF8());
		setInputState(false);
	}
}

void ResultUIController::setInputState(const bool flg)
{
	input_state_ = flg;
}
