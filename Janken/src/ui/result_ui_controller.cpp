#include "result_ui_controller.h"
#include "../constants/constants.h"


ResultUIController::ResultUIController() : result_font_(100, Typeface::Bold, FontStyle::Bitmap), return_btn_(SimpleGUI::ButtonRegionAt(Constants::Result::ReturnBtnStr, Constants::Result::ReturnBtnCenterPos, 300))
{

}


void ResultUIController::draw() const
{
	
	// TODO
	// ���𐔂̕\��
	result_font_(Constants::Result::ResultStr).draw(Arg::center = Constants::Result::ResultCenterPos.movedBy(1.5, 2), Constants::ShadowColor);   // �e������
	result_font_(Constants::Result::ResultStr).draw(Arg::center = Constants::Result::ResultCenterPos, Constants::Result::ResultColor);
	String score = Format(result_score);
	result_font_(score).draw(Arg::center = Constants::Result::ScoreCenterPos, Constants::Result::ResultColor);

	// �^�C�g���ɖ߂�{�^���\��
	SimpleGUI::ButtonAt(Constants::Result::ReturnBtnStr, Constants::Result::ReturnBtnCenterPos, 300);
}

void ResultUIController::update()
{

	// �^�C�g���ɖ߂�{�^�����N���b�N
	if (return_btn_.leftClicked()) {
		onStartBtnClickedCallback.invoke();
	}
}

