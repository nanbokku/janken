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

	constexpr Size WindowSize(1200, 900);
	constexpr ColorF BackgroundColor(0.3, 0.6, 1.0);
	constexpr ColorF ShadowColor(0.0, 0.5);

	struct Score
	{
		int correct_answers = 0;
	};

	struct Title
	{
		static const String TitleStr;
		static const String StartBtnStr;
		static const Vec2 TitleCenterPos;
		static const Vec2 StartBtnCenterPos;
		static constexpr Color TitleColor = Palette::White;
	};

	struct Play
	{
		static constexpr int MaxCountdown = 3;
		static constexpr int MaxWaitMs = 3000;
		static constexpr int MaxNumOfQuestions = 10;
	};
}