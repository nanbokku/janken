#include "constants.h"

using namespace Constants;

const String Title::TitleStr = String(U"�ゾ���W�����P��");
const String Title::StartBtnStr = String(U"�X�^�[�g");
const Vec2 Title::TitleCenterPos = Vec2(WindowSize.x / 2, WindowSize.y / 4);
const Vec2 Title::StartBtnCenterPos = Vec2(WindowSize.x / 2, WindowSize.y * 3 / 4);

const String Constants::Audio::JankenponStr = U"jankenpon";
const String Constants::Audio::CorrectStr = U"correct2";
const String Constants::Audio::IncorrectStr = U"incorrect1";

const String Result::ResultStr = String(U"�X�R�A");
const String Result::ReturnBtnStr = String(U"�X�^�[�g��ʂɖ߂�");
const String Result::RankingBtnStr = String(U"�����L���O");
const Vec2 Result::ResultCenterPos = Vec2(WindowSize.x / 2, WindowSize.y / 4);
const Vec2 Result::ScoreCenterPos = Vec2(WindowSize.x / 2, WindowSize.y / 2);
const Vec2 Result::ReturnBtnCenterPos = Vec2(WindowSize.x / 3 * 1, WindowSize.y * 3 / 4);
const Vec2 Result::RankingBtnCenterPos = Vec2(WindowSize.x / 3 * 2, WindowSize.y * 3 / 4);
