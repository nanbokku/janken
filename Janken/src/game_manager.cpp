#include "game_manager.h"

#include <Siv3D.hpp>
#include <HamFramework/SceneManager.hpp>

#include "scene/title.h"
#include "scene/play.h"
#include "scene/result.h"

GameManager::GameManager()
{
	manager_ = std::make_shared<SceneManager<Constants::Scene>>();
}

GameManager::~GameManager()
{
	manager_.reset();
}

void GameManager::initialize()
{
	Window::SetTitle(Constants::Title::TitleStr);
	Window::Resize(Constants::WindowSize);
	Window::Centering();

	manager_->add<TitleScene>(Constants::Scene::Title);
	manager_->add<PlayScene>(Constants::Scene::Play);
	manager_->add<ResultScene>(Constants::Scene::Result);
}

void GameManager::loop()
{
	while (System::Update()) {
		if (!manager_->update()) {
			break;
		}
	}
}

void GameManager::exit()
{
}