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