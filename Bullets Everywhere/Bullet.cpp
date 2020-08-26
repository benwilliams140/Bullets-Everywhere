#include "Bullet.h"

Bullet::Bullet(float _angle, sf::Vector2f _pos) : GameObject("./assets/bullet.png", _pos, 3.0f)
{
	rect.setRotation(_angle);

	float _rad = _angle * M_PI / 180;
	setXVel(cos(_rad) * speed);
	setYVel(sin(_rad) * speed);
}

Bullet::~Bullet()
{
	std::cout << "Bullet dtor" << std::endl;
}