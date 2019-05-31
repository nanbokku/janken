#include "./ranking.h"

#include "../constants/constants.h"

RankingScene::RankingScene(const InitData& data) : IScene(data), ui_controller_()
{
	initialize();
}

void RankingScene::update()
{
	ui_controller_.update();
}

void RankingScene::draw() const
{
	ui_controller_.draw();
}

void RankingScene::initialize()
{
	// タイトルボタンクリック時のコールバックを登録
	ui_controller_.onTitleBtnClickedCallback.set([&]() {
		this->exit();
		changeScene(Constants::Scene::Title);
	});
}

void RankingScene::exit()
{
	ui_controller_.onTitleBtnClickedCallback.unset();
}