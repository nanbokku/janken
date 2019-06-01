#include "ranking_ui_controller.h"

#include "../constants/constants.h"

using namespace std;

RankingUIController::RankingUIController() : font_(50, Typeface::Heavy, FontStyle::Bitmap), return_btn_(SimpleGUI::ButtonRegionAt(Constants::Ranking::ReturnBtnStr, Constants::Ranking::ReturnBtnCenterPos, 300))
{

}

void RankingUIController::draw() const
{
	// ƒ‰ƒ“ƒLƒ“ƒO‚Ì•`‰æ
	for (int i = 0; i < rects_.size(); i++) {
		rects_[i].draw(ColorF(1.0, 0.2));

		if (i < ranks_.size()) {
			String data = ranks_[i] + U". " + names_[i] + U" ";
			font_(data).draw(Arg::leftCenter = Vec2(rects_[i].leftCenter().x + 50, rects_[i].leftCenter().y));
			font_(scores_[i]).draw(Arg::rightCenter = Vec2(rects_[i].rightCenter().x - 50, rects_[i].rightCenter().y));
		}
	}

	SimpleGUI::ButtonAt(Constants::Ranking::ReturnBtnStr, Constants::Ranking::ReturnBtnCenterPos, 300);
}

void RankingUIController::update()
{
	if (return_btn_.leftClicked()) {
		onTitleBtnClickedCallback.invoke();
	}
}

void RankingUIController::initialize(const vector<vector<string>>& ranking)
{
	vector<String> ranks;
	vector<String> scores;
	vector<String> names;

	int current_rank = 0, current_score = 999999;
	for (auto rank : ranking)
	{
		string name = rank[0];
		int score = stoi(rank[1]);

		if (score < current_score) {
			current_score = score;
			current_rank++;
		}

		ranks.push_back(ToString(current_rank));
		scores.push_back(ToString(score));
		names.push_back(Unicode::Widen(name));
	}

	ranks_ = vector<String>(ranks);
	scores_ = vector<String>(scores);
	names_ = vector<String>(names);
}