#include "constants.h"

using namespace Constants;

const String Title::TitleStr = String(U"後だしジャンケン");
const String Title::StartBtnStr = String(U"スタート");
const Vec2 Title::TitleCenterPos = Vec2(WindowSize.x / 2, WindowSize.y / 4);
const Vec2 Title::StartBtnCenterPos = Vec2(WindowSize.x / 2, WindowSize.y * 3 / 4);

const String Constants::Audio::JankenponStr = U"jankenpon";
const String Constants::Audio::PonStr = U"pon";

const String Result::ResultStr = String(U"正解数");
const String Result::ReturnBtnStr = String(U"スタート画面に戻る");
const Vec2 Result::ResultCenterPos = Vec2(WindowSize.x / 2, WindowSize.y / 4);
const Vec2 Result::ReturnBtnCenterPos = Vec2(WindowSize.x / 2, WindowSize.y * 3 / 4);
