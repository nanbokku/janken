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
	Constants::Score& data = getData();	// Score�\����
	auto count = data.correct_answers;
	auto time = data.time_score;
	ui_controller_.result_score = count / time + 100;
	return  (count *10000 /time);
}



void ResultScene::initialize()
{
	Print << U"result scene";

	// �X�^�[�g�{�^���������ꂽ�Ƃ��̃R�[���o�b�N��o�^
	ui_controller_.onStartBtnClickedCallback.set([&] {
		// �^�C�g���ɖ߂�
		this->exit();
		this->changeScene(Constants::Scene::Title);
	});
}

void ResultScene::exit()
{ 
}