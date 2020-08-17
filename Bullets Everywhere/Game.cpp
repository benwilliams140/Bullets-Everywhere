#include "Game.h"

Game::Game()
{
	window = new Window(windowTitle, windowWidth, windowHeight);
	mouse = new Mouse(window);
	player = new Player(window);

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

		if (_event.type == sf::Event::KeyPressed)
		{
			if (_event.key.code == sf::Keyboard::A) player->setDx(-1); // left
			if (_event.key.code == sf::Keyboard::D) player->setDx(1); // right
			if (_event.key.code == sf::Keyboard::W) player->setDy(-1); // up
			if (_event.key.code == sf::Keyboard::S) player->setDy(1); // down
		}

		if (_event.type == sf::Event::KeyReleased)
		{
			if (_event.key.code == sf::Keyboard::A || _event.key.code == sf::Keyboard::D)
				player->setDx(0);
			if (_event.key.code == sf::Keyboard::W || _event.key.code == sf::Keyboard::S)
				player->setDy(0);
		}
	}
}

void Game::update(float _deltaTime)
{
	if (state == State::PAUSED) return;

	mouse->update(_deltaTime);
	player->update(_deltaTime);

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
	player->render();

	for (auto it = objects.begin(); it != objects.end(); ++it)
	{
		GameObject* _object = *it;
		_object->render();
	}

	window->display();
}