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
	Constants::Score& data = getData();	// Score�\����
	auto count = data.correct_answers;
	auto time = data.time_score;
	ui_controller_.result_score = (count * 100000 / time);

	// �����L���O���X�V����Ƃ�
	if (ranking_.needUpdate(ui_controller_.result_score)) {
		ui_controller_.setInputState(true);
	}
}

void ResultScene::initialize()
{
	ResultScore();

	// �X�^�[�g�{�^���������ꂽ�Ƃ��̃R�[���o�b�N��o�^
	ui_controller_.onStartBtnClickedCallback.set([&] {
		// �^�C�g���ɖ߂�
		this->exit();
		this->changeScene(Constants::Scene::Title);
	});

	// �����L���O�{�^���������ꂽ�Ƃ��̃R�[���o�b�N
	ui_controller_.onRankingBtnClickedCallback.set([&] {
		// �����L���O
		this->exit();
		this->changeScene(Constants::Scene::Ranking);
	});

	// ���O�����͂��ꂽ�Ƃ��̃R�[���o�b�N
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