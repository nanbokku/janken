#pragma once

#include "../event/event.h"

class GameStateBase
{
public:
	GameStateBase() = default;
	virtual ~GameStateBase() = default;

	virtual void initialize() = 0;	// ステートの開始時によぶ
	virtual void update() = 0;	// 毎フレーム
	virtual void draw() = 0;	// 毎フレーム
	virtual void exit() = 0;	// ステートの終了時

	// ステートが終了したときのコールバック
	Event<void, const std::shared_ptr<GameStateBase>&> onStateFinishedCallback;
};