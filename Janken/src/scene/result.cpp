#include "result.h"

#include <Siv3D.hpp>
#include "../constants/constants.h"

ResultScene::ResultScene(const InitData& data) : IScene(data), ui_controller_(), ranking_()
{
	initialize();
}

void ResultScene::update()
{
	ui_controller_.update();
}

void ResultScene::draw() const
{
	ui_controller_.draw();
}

void ResultScene::ResultScore()
{
	Constants::Score& data = getData();	// Score構造体
	auto count = data.correct_answers;
	auto time = data.time_score;
	ui_controller_.result_score = (count * 100000 / time);

	// ランキングを更新するとき
	if (ranking_.needUpdate(ui_controller_.result_score)) {
		ui_controller_.setInputState(true);
	}
}

void ResultScene::initialize()
{
	ResultScore();

	// スタートボタンが押されたときのコールバックを登録
	ui_controller_.onStartBtnClickedCallback.set([&] {
		// タイトルに戻る
		this->exit();
		this->changeScene(Constants::Scene::Title);
	});

	// ランキングボタンが押されたときのコールバック
	ui_controller_.onRankingBtnClickedCallback.set([&] {
		// ランキング
		this->exit();
		this->changeScene(Constants::Scene::Ranking);
	});

	// 名前が入力されたときのコールバック
	ui_controller_.onNameInputedCallback.set([&](std::string name) {
		this->ranking_.update(name, ui_controller_.result_score);

		this->exit();
		this->changeScene(Constants::Scene::Ranking);
	});
}

void ResultScene::exit()
{ 
	ui_controller_.onStartBtnClickedCallback.unset();
}