#include "Player.h"

Player::Player(sf::Vector2f _pos) : GameObject("./assets/player.png", _pos)
{
	currentGun = NULL;
}

Player::~Player()
{

}

void Player::update(float _deltaTime)
{
	currentGun->update(rect.getPosition(), _deltaTime);
	GameObject::update(_deltaTime);
}

void Player::render(Window* _window)
{
	currentGun->render(_window);
	GameObject::render(_window);
}

Bullet* Player::shoot()
{
	return currentGun->shoot();
}

void Player::addGun(Gun* _gun)
{
	currentGun = _gun;
	guns.push_back(_gun);
}


Gun* Player::dropCurrentGun()
{
	Gun* _droppedGun = currentGun;
	guns.pop_back();
	currentGun = guns.back();
	return _droppedGun;
}