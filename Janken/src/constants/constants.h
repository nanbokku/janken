#pragma once

#include <Siv3D.hpp>

namespace Constants
{
	const enum class Scene
	{
		Title,
		Play,
		Result
	};

	const enum class GameState
	{
		Countdown,
		Play
	};

	constexpr Size WindowSize(800, 600);

	struct Title
	{
		static const String TitleStr;
		static const String StartBtnStr;
	};

	struct Play
	{
		static constexpr int MaxCountdown = 3;
	};
}