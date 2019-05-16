#include "janken_generator.h"

Constants::HandGesture JankenGenerator::randomHand()
{
	// 手をランダムに決定
	//乱数を生成
	std::random_device rnd;
	std::mt19937 mt(rnd());
	std::uniform_int_distribution<> rand100(1, 99);

	//乱数の結果により，手を決める
	if (rand100(mt) % 3 == 0)
		return Constants::HandGesture::Goo;
	else if (rand100(mt) % 3 == 1)
		return Constants::HandGesture::Choki;
	else
		return Constants::HandGesture::Pa;
}

bool JankenGenerator::isWinningOrLosing()
{
	// ランダムで勝つか負けるかを決める
	//乱数を生成
	std::random_device rnd;
	std::mt19937 mt(rnd());
	std::uniform_int_distribution<> rand100(0, 99);

	//乱数の結果により，勝ち負けを決める
	if (rand100(mt) % 2 == 0) return true;
	else  return false;
}