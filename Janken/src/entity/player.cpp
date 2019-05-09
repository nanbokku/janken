#include "player.h"

Player::Player() : hand_(Constants::HandGesture::None), is_active_(false)
{

}

void Player::setActive(bool active)
{
	is_active_ = active;
}

void Player::observeHand()
{
	// TODO
	// leap motion‚©‚çHandGesture‚ðŽæ“¾
	// hand_‚ÉŠi”[
}