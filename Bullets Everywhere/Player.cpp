#include "Player.h"

Player::Player(sf::Vector2f _pos) : GameObject("./assets/player.png", _pos)
{
	dx = 0;
	dy = 0;
}

Player::~Player()
{

}

void Player::update(float _deltaTime)
{
	sf::Vector2f _pos = rect.getPosition();
	rect.setPosition(sf::Vector2f(_pos.x + dx, _pos.y + dy));
}

void Player::setDx(int _dx)
{
	dx = _dx;
}

void Player::setDy(int _dy)
{
	dy = _dy;
}