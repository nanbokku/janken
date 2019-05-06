#include "play.h"

#include "../game_state/gs_countdown.h"

PlayScene::PlayScene(const InitData& data) : SceneBase(data)
{
	initialize();
}

void PlayScene::update()
{
	current_state_->update();
}

void PlayScene::draw() const
{
	current_state_->draw();
}

void PlayScene::initialize()
{
	ClearPrint();
	Print << U"initialize play";

	changeState(std::make_shared<GS_Countdown>());
}

void PlayScene::exit()
{
	Print << U"exit play";

	current_state_->exit();
}

void PlayScene::changeState(const std::shared_ptr<GameStateBase> state)
{
	if (current_state_) {
		current_state_->exit();
		current_state_->setStateFinishedCallback(nullptr);
	}

	current_state_ = state;

	// ƒCƒxƒ“ƒg‚Ì“o˜^
	current_state_->setStateFinishedCallback(
		[&](std::shared_ptr<GameStateBase> state) {this->changeState(state); }
	);
	
	current_state_->initialize();
}