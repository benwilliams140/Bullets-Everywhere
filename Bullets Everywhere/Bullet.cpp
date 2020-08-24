#include "Bullet.h"

Bullet::Bullet(float _angle, sf::Vector2f _pos) : GameObject("./assets/bullet.png", _pos)
{
	rect.setRotation(_angle);

	float _rad = _angle * M_PI / 180;
	setXVel(cos(_rad));
	setYVel(sin(_rad));
}

Bullet::~Bullet()
{

}