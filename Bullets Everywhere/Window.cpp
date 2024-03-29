#include "Window.h"

Window::Window(std::string _title, int _width, int _height) : width(_width), height(_height)
{
	sf::VideoMode _vm(width, height);
	window.create(_vm, sf::String(_title), sf::Style::Default);
}

Window::~Window()
{

}

void Window::setFrameLimit(int _limit)
{
	window.setFramerateLimit(_limit);
}

bool Window::pollEvent(sf::Event& _event)
{
	return window.pollEvent(_event);
}

bool Window::isOpen()
{
	return window.isOpen();
}

void Window::close()
{
	window.close();
}

void Window::clear(sf::Color _color)
{
	window.clear(_color);
}

void Window::display()
{
	window.display();
}

void Window::render(sf::Shape& _shape)
{
	window.draw(_shape);
}

sf::Vector2f Window::getMousePosition()
{
	sf::Vector2i _pos = sf::Mouse::getPosition(window);
	return sf::Vector2f(_pos.x, _pos.y);
}

sf::RenderWindow& Window::getWindow()
{
	return window;
}

int Window::getWidth()
{
	return width;
}

int Window::getHeight()
{
	return height;
}