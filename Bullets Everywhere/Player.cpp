#include "Player.h"

Player::Player(sf::Vector2f _pos) : GameObject("./assets/player.png", _pos, 2.0f)
{
	currentGun = NULL;
}

Player::~Player()
{

}

void Player::update(float _deltaTime)
{
	if(currentGun) currentGun->update(rect.getPosition(), _deltaTime);
	GameObject::update(_deltaTime);
}

void Player::render(Window* _window)
{
	if(currentGun) currentGun->render(_window);
	GameObject::render(_window);
}

Bullet* Player::shoot()
{
	if(currentGun) return currentGun->shoot();
	return NULL;
}

void Player::addGun(Gun* _gun)
{
	currentGun = _gun;
	guns.push_back(_gun);
}


Gun* Player::dropCurrentGun()
{
	Gun* _droppedGun = currentGun;
	currentGun = NULL;
	return _droppedGun;
}