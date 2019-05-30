#include "result.h"

#include <Siv3D.hpp>
#include "../constants/constants.h"

ResultScene::ResultScene(const InitData& data) : IScene(data), ui_controller_()
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

int ResultScene::ResultScore()
{
	Constants::Score& data = getData();	// Score構造体
	auto count = data.correct_answers;
	auto time = data.time_score;
	ui_controller_.result_score = count / time + 100;
	return  (count *10000 /time);
}



void ResultScene::initialize()
{
	Print << U"result scene";

	// スタートボタンが押されたときのコールバックを登録
	ui_controller_.onStartBtnClickedCallback.set([&] {
		// タイトルに戻る
		this->exit();
		this->changeScene(Constants::Scene::Title);
	});
}

void ResultScene::exit()
{ 
}