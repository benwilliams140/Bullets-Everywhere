#ifndef BULLET_H
#define BULLET_H

#include "GameObject.h"
#include "Mouse.h"

class Bullet : public GameObject
{
public:
	Bullet(float, sf::Vector2f);
	~Bullet();

private:
};

#endif