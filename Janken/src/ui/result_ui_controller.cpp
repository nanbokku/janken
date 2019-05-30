#include "result_ui_controller.h"
#include "../constants/constants.h"


ResultUIController::ResultUIController() : result_font_(100, Typeface::Bold, FontStyle::Bitmap), return_btn_(SimpleGUI::ButtonRegionAt(Constants::Result::ReturnBtnStr, Constants::Result::ReturnBtnCenterPos, 300))
{

}


void ResultUIController::draw() const
{
	
	// TODO
	// 正解数の表示
	result_font_(Constants::Result::ResultStr).draw(Arg::center = Constants::Result::ResultCenterPos.movedBy(1.5, 2), Constants::ShadowColor);   // 影をつける
	result_font_(Constants::Result::ResultStr).draw(Arg::center = Constants::Result::ResultCenterPos, Constants::Result::ResultColor);
	String score = Format(result_score);
	result_font_(score).draw(Arg::center = Constants::Result::ScoreCenterPos, Constants::Result::ResultColor);

	// タイトルに戻るボタン表示
	SimpleGUI::ButtonAt(Constants::Result::ReturnBtnStr, Constants::Result::ReturnBtnCenterPos, 300);
}

void ResultUIController::update()
{

	// タイトルに戻るボタンをクリック
	if (return_btn_.leftClicked()) {
		onStartBtnClickedCallback.invoke();
	}
}

