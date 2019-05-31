#include "ranking_ui_controller.h"

#include "../constants/constants.h"

using namespace std;

RankingUIController::RankingUIController() : font_(50, Typeface::Heavy, FontStyle::Bitmap), return_btn_(SimpleGUI::ButtonRegionAt(Constants::Ranking::ReturnBtnStr, Constants::Ranking::ReturnBtnCenterPos, 300))
{

}

void RankingUIController::draw() const
{
	for (auto rect : rects_) {
		rect.draw(ColorF(1.0, 0.2));
	}

	SimpleGUI::ButtonAt(Constants::Ranking::ReturnBtnStr, Constants::Ranking::ReturnBtnCenterPos, 300);
}

void RankingUIController::update()
{
	if (return_btn_.leftClicked()) {
		onTitleBtnClickedCallback.invoke();
	}
}