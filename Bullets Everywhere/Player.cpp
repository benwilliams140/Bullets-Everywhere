#include "Player.h"

Player::Player(Window* _window) : GameObject(_window, "./assets/player.png", _window->getWidth() / 2, _window->getHeight() / 2)
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