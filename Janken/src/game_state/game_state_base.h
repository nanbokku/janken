#pragma once

#include <functional>

class GameStateBase
{
public:
	GameStateBase() = default;
	virtual ~GameStateBase() = default;

	virtual void initialize() = 0;	// ステートの開始時によぶ
	virtual void update() = 0;	// 毎フレーム
	virtual void draw() = 0;	// 毎フレーム
	virtual void exit() = 0;	// ステートの終了時

	inline void setStateFinishedCallback(const std::function<void(const std::shared_ptr<GameStateBase>&)>& callback)
	{
		onStateFinishedCallback_ = callback;
	}

protected:
	inline void invokeStateFinishedCallback(const std::shared_ptr< GameStateBase>& state)
	{
				if (onStateFinishedCallback_) {
			onStateFinishedCallback_(state);
		}
	}

private:
	// ステートが終了したときのコールバック
	std::function<void(const std::shared_ptr<GameStateBase>&)> onStateFinishedCallback_;
};