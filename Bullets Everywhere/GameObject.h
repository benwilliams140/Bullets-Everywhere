#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <iostream>

#include "Window.h"

class GameObject
{
public:
	GameObject(Window*, std::string, float = 0.0f, float = 0.0f);
	~GameObject();

	virtual void update(float);
	virtual void render();

protected:
	Window* window;

	sf::RectangleShape rect;

private:
	sf::Texture tex;
};

#endif