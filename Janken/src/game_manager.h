#pragma once

#include <memory>
#include "constants/constants.h"

// forward declaration
namespace s3d
{
	namespace detail
	{
		struct EmptyData;
	}
	template<class State, class Data>
	class SceneManager;
}

// singleton class
class GameManager
{
public:
	GameManager(const GameManager&) = delete;
	GameManager operator=(const GameManager&) = delete;
	GameManager(GameManager&&) = delete;
	GameManager& operator=(const GameManager&&) = delete;

	void initialize();
	void loop();
	void exit();

	static GameManager& instance()
	{
		static GameManager singleton;
		return singleton;
	}

private:
	GameManager();
	~GameManager();

	std::shared_ptr<s3d::SceneManager<Constants::Scene, s3d::detail::EmptyData>> manager_;
};