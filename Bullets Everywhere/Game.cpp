#include "Game.h"

Game::Game()
{
	window = new Window(windowTitle, windowWidth, windowHeight);
	mouse = new Mouse(window);

	state = State::PAUSED;
}

Game::~Game()
{

}

void Game::run()
{
	state = State::RUNNING;

	sf::Clock _clock;
	window->setFrameLimit(frameLimit);

	while (state != State::EXIT)
	{
		processInput();
		update(_clock.restart().asSeconds());
		render();
	}
}

void Game::processInput()
{
	sf::Event _event;
	while (window->pollEvent(_event))
	{
		if (_event.type == sf::Event::Closed) state = State::EXIT;
	}
}

void Game::update(float _deltaTime)
{
	if (state == State::PAUSED) return;

	mouse->update(_deltaTime);

	for (auto it = objects.begin(); it != objects.end(); ++it)
	{
		GameObject* _object = *it;
		_object->update(_deltaTime);
	}
}

void Game::render()
{
	window->clear(sf::Color::Black);

	mouse->render();

	for (auto it = objects.begin(); it != objects.end(); ++it)
	{
		GameObject* _object = *it;
		_object->render();
	}

	window->display();
}