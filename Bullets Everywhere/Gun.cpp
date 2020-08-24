#include "Gun.h"

Gun::Gun(Mouse* _mouse) : mouse(_mouse),
	GameObject("./assets/gun.png")
{
	
}

Gun::~Gun()
{

}

void Gun::update(sf::Vector2f _playerPos, float _deltaTime)
{
	sf::Vector2f _mousePos = mouse->getPosition();
	int _direction;

	if (_mousePos.x < _playerPos.x) _direction = -1;
	else _direction = 1;

	rect.setScale(sf::Vector2f(1, _direction));

	float _deltaX = _mousePos.x - _playerPos.x;
	float _deltaY = _mousePos.y - _playerPos.y;

	float _angle = atan2(_deltaY, _deltaX) * 180 / M_PI;
	//std::cout << _angle << std::endl;

	float _rad = _angle * M_PI / 180;
	rect.setPosition(_playerPos + sf::Vector2f(cos(_rad) * 35, sin(_rad) * 35));

	rect.setRotation(_angle);
}

void Gun::render(Window* _window)
{
	//bullet->render(_window);
	GameObject::render(_window);
}

Bullet* Gun::shoot()
{
	return new Bullet(rect.getRotation(), rect.getPosition());
}