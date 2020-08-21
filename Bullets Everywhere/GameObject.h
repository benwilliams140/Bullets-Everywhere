#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>

#include "Window.h"

class GameObject
{
public:
	GameObject(std::string, sf::Vector2f = sf::Vector2f(0.0f, 0.0f));
	~GameObject();

	virtual void update(float);
	virtual void render(Window*);

	sf::Vector2f getPos();

	sf::Vector2f setXVel(float);
	sf::Vector2f setYVel(float);

protected:
	sf::RectangleShape rect;
	sf::Vector2f velocity;

private:
	sf::Texture tex;
};

#endif