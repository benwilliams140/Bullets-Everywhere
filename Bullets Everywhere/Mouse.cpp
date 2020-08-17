#include "Mouse.h"

Mouse::Mouse(Window* _window) :  window(_window),
	GameObject("./assets/target.png")
{

}

Mouse::~Mouse()
{

}

void Mouse::update(float _deltaTime)
{
	sf::Vector2f _pos = window->getMousePosition();
	_pos.x = _pos.x < 0 ? 0 : _pos.x > window->getWidth() ? window->getWidth() : _pos.x;
	_pos.y = _pos.y < 0 ? 0 : _pos.y > window->getHeight() ? window->getHeight() : _pos.y;

	rect.setPosition(_pos);
}