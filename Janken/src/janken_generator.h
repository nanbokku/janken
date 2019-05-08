#pragma once

#include "constants/constants.h"

class JankenGenerator
{
public:
	JankenGenerator() = default;
	~JankenGenerator() = default;

	// ランダムに手を決定する
	Constants::HandGesture randomHand();
	// 問題文「勝て(true)」or「負けろ(false)」
	bool isWinningOrLosing();
};