#include "title_ui_controller.h"
#include "../constants/constants.h"

TitleUIController::TitleUIController() : title_font_(100,Typeface::Bold,FontStyle::Bitmap), start_btn_(SimpleGUI::ButtonRegionAt(Constants::Title::StartBtnStr, Constants::Title::StartBtnCenterPos, 300))
{

}

void TitleUIController::draw() const
{
	// �^�C�g��
	title_font_(Constants::Title::TitleStr).draw(Arg::center = Constants::Title::TitleCenterPos.movedBy(1.5, 2), Constants::ShadowColor);   // �e������
	title_font_(Constants::Title::TitleStr).draw(Arg::center = Constants::Title::TitleCenterPos, Constants::Title::TitleColor);
	
	// �X�^�[�g�{�^��
	// TODO: �{�^���N���X�쐬����
	SimpleGUI::ButtonAt(Constants::Title::StartBtnStr, Constants::Title::StartBtnCenterPos, 300);
}

void TitleUIController::update()
{
	// �X�^�[�g�{�^�����N���b�N
	if (start_btn_.leftClicked()) {
		onStartBtnClickedCallback.invoke();
	}
}