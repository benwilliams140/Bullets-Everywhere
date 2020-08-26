#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>

#include "Window.h"

class GameObject
{
public:
	GameObject(std::string, sf::Vector2f = sf::Vector2f(0.0f, 0.0f), float = 1.0f);
	~GameObject();

	virtual void update(float);
	virtual void render(Window*);

	bool inBounds(Window*);

	sf::Vector2f getPosition();

	sf::Vector2f setXVel(float);
	sf::Vector2f setYVel(float);
	void setPosition(sf::Vector2f);

protected:
	sf::RectangleShape rect;
	sf::Vector2f velocity;
	float speed;

private:
	sf::Texture tex;
};

#endif