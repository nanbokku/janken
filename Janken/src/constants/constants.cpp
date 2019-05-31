#include "constants.h"

using namespace Constants;

const String Title::TitleStr = String(U"後だしジャンケン");
const String Title::StartBtnStr = String(U"スタート");
const Vec2 Title::TitleCenterPos = Vec2(WindowSize.x / 2, WindowSize.y / 4);
const Vec2 Title::StartBtnCenterPos = Vec2(WindowSize.x / 2, WindowSize.y * 3 / 4);

const String Constants::Audio::JankenponStr = U"jankenpon";
const String Constants::Audio::CorrectStr = U"correct2";
const String Constants::Audio::IncorrectStr = U"incorrect1";

const String Result::ResultStr = String(U"スコア");
const String Result::ReturnBtnStr = String(U"スタート画面に戻る");
const String Result::RankingBtnStr = String(U"ランキング");
const Vec2 Result::ResultCenterPos = Vec2(WindowSize.x / 2, WindowSize.y / 4);
const Vec2 Result::ScoreCenterPos = Vec2(WindowSize.x / 2, WindowSize.y / 2);
const Vec2 Result::ReturnBtnCenterPos = Vec2(WindowSize.x / 3 * 1, WindowSize.y * 3 / 4);
const Vec2 Result::RankingBtnCenterPos = Vec2(WindowSize.x / 3 * 2, WindowSize.y * 3 / 4);
