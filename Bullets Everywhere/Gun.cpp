#include "Gun.h"

Gun::Gun(Player* _player, Mouse* _mouse) : player(_player), mouse(_mouse),
	GameObject("./assets/gun.png", _player->getPos())
{

}

Gun::~Gun()
{

}

void Gun::update(float _deltaTime)
{
	sf::Vector2f _mousePos = mouse->getPos();
	sf::Vector2f _playerPos = player->getPos();
	int dir;

	if (_mousePos.x < _playerPos.x) dir = -1;
	else dir = 1;

	rect.setScale(sf::Vector2f(dir, 1));
	rect.setPosition(sf::Vector2f(_playerPos.x + dir * 20, _playerPos.y));
}