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
	ClearPrint();
	Print << U"initialize title";

	// �X�^�[�g�{�^���N���b�N���̃R�[���o�b�N�o�^
	ui_controller_.onStartBtnClickedCallback.set([&]() {
		this->exit();
		this->changeScene(Constants::Scene::Play);
	});
}

void TitleScene::exit()
{
	Print << U"exit title";

	ui_controller_.onStartBtnClickedCallback.unset();
}