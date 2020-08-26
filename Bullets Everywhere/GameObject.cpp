#include "GameObject.h"

GameObject::GameObject(std::string _fileName, sf::Vector2f _pos, float _speed) : speed(_speed)
{
	if (tex.loadFromFile(_fileName))
		std::cout << "Successfully loaded texture file: " << _fileName << std::endl;
	else
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
	rect.setPosition(rect.getPosition() + velocity * speed);
}

void GameObject::render(Window* _window)
{
	_window->render(rect);
}

bool GameObject::inBounds(Window* _window)
{
	int _lowerX = rect.getPosition().x - rect.getSize().x / 2;
	int _upperX = rect.getPosition().x + rect.getSize().x / 2;
	int _lowerY = rect.getPosition().y - rect.getSize().y / 2;
	int _upperY = rect.getPosition().y + rect.getSize().y / 2;

	return _lowerX >= 0 && _upperX <= _window->getWidth() && _lowerY >= 0 && _upperY <= _window->getHeight();
}

sf::Vector2f GameObject::getPosition()
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

void GameObject::setPosition(sf::Vector2f _pos)
{
	rect.setPosition(_pos);
}