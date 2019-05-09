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

	const enum class HandGesture
	{
		Goo,
		Choki,
		Pa,
		None
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
		static constexpr int MaxWaitMs = 3000;
		static constexpr int MaxNumOfQuestions = 10;
	};
}