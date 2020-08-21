#ifndef GUN_H
#define GUN_H

#include "GameObject.h"
#include "Mouse.h"
#include "Window.h"
#include "Bullet.h"

class Gun : public GameObject
{
public:
	Gun(Mouse*);
	~Gun();

	void update(sf::Vector2f, float);
	Bullet* shoot();

private:
	Mouse* mouse;
};

#endif