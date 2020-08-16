#include "GameObject.h"

GameObject::GameObject(Window* _window, std::string _fileName, float _xPos, float _yPos) : window(_window)
{
	if (!tex.loadFromFile(_fileName))
		std::cout << "Unable to load texture file: " << _fileName << std::endl;

	rect.setTexture(&tex, true);
	
	float _width = rect.getTextureRect().width;
	float _height = rect.getTextureRect().height;

	rect.setSize(sf::Vector2f(_width, _height));
	rect.setOrigin(sf::Vector2f(_width / 2, _height / 2));
	rect.setPosition(sf::Vector2f(_xPos, _yPos));
}

GameObject::~GameObject()
{

}

void GameObject::update(float _deltaTime)
{

}

void GameObject::render()
{
	window->render(rect);
}