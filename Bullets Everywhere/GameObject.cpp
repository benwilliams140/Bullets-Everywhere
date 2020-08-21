#include "GameObject.h"

GameObject::GameObject(std::string _fileName, sf::Vector2f _pos)
{
	if (!tex.loadFromFile(_fileName))
		std::cout << "Unable to load texture file: " << _fileName << std::endl;

	rect.setTexture(&tex, true);
	
	float _width = rect.getTextureRect().width;
	float _height = rect.getTextureRect().height;

	rect.setSize(sf::Vector2f(_width, _height));
	rect.setOrigin(sf::Vector2f(_width / 2, _height / 2));
	rect.setPosition(_pos);
}

GameObject::~GameObject()
{

}

void GameObject::update(float _deltaTime)
{
	rect.setPosition(rect.getPosition() + velocity);
}

void GameObject::render(Window* _window)
{
	_window->render(rect);
}

sf::Vector2f GameObject::getPos()
{
	return rect.getPosition();
}

sf::Vector2f GameObject::setXVel(float _xVel)
{
	velocity.x = _xVel;
	return velocity;
}

sf::Vector2f GameObject::setYVel(float _yVel)
{
	velocity.y = _yVel;
	return velocity;
}