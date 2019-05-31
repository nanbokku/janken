#include "title.h"

#include <Siv3D.hpp>

TitleScene::TitleScene(const InitData& data) : IScene(data), ui_controller_()
{
	initialize();
}

void TitleScene::update()
{
	ui_controller_.update();
}

void TitleScene::draw() const
{
	ui_controller_.draw();
}

void TitleScene::initialize()
{
	// スタートボタンクリック時のコールバック登録
	ui_controller_.onStartBtnClickedCallback.set([&]() {
		this->exit();
		this->changeScene(Constants::Scene::Play);
	});
}

void TitleScene::exit()
{
	ui_controller_.onStartBtnClickedCallback.unset();
}