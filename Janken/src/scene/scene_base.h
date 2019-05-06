#pragma once

#include <HamFramework/SceneManager.hpp>

#include "../constants/constants.h"

// TODO:消すかも
class SceneBase : public SceneManager<Constants::Scene>::Scene
{
public:
	SceneBase(const InitData& data) : IScene(data)
	{
	}

	virtual void initialize() = 0;	// REVIEW: 無くていいかも
	virtual void exit() = 0;

protected:
	// シーン変更時に呼ぶ
	// exit()忘れ防止のため，IScene::changeScene()は使用しない
	void onSceneChanged(Constants::Scene scene)
	{
		exit();
		changeScene(scene);
	}
};