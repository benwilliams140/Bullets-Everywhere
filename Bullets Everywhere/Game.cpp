#include "Game.h"

Game::Game() : totalTimeElapsed(0.0f)
{
	window = new Window(windowTitle, windowWidth, windowHeight);
	mouse = new Mouse(window);
	player = new Player(sf::Vector2f(windowWidth / 2, windowHeight / 2));

	player->addGun(new Gun(mouse));

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
			if (_event.key.code == sf::Keyboard::A) player->setXVel(-1); // left
			if (_event.key.code == sf::Keyboard::D) player->setXVel(1); // right
			if (_event.key.code == sf::Keyboard::W) player->setYVel(-1); // up
			if (_event.key.code == sf::Keyboard::S) player->setYVel(1); // down
			
			if (_event.key.code == sf::Keyboard::Q) player->dropCurrentGun();
		}

		if (_event.type == sf::Event::KeyReleased)
		{
			if (_event.key.code == sf::Keyboard::A || _event.key.code == sf::Keyboard::D)
				player->setXVel(0);
			if (_event.key.code == sf::Keyboard::W || _event.key.code == sf::Keyboard::S)
				player->setYVel(0);
		}

		if (_event.type == sf::Event::MouseButtonPressed)
		{
			if (_event.key.code == sf::Mouse::Left)
			{
				Bullet* _bullet = player->shoot();
				if (_bullet) bullets.push_back(_bullet);
			}
		}
	}
}

void Game::update(float _deltaTime)
{
	if (state == State::PAUSED) return;

	totalTimeElapsed += _deltaTime;

	mouse->update(_deltaTime);
	player->update(_deltaTime);

	for (auto _it = bullets.begin(); _it != bullets.end(); )
	{
		Bullet* _bullet = *_it;
		_bullet->update(_deltaTime);
		
		if (_bullet->inBounds(window)) ++_it;
		else
		{
			Bullet* _temp = *_it;
			_it = bullets.erase(_it);
			delete _temp;
		}
	}
}

void Game::render()
{
	window->clear(sf::Color::Black);

	mouse->render(window);
	player->render(window);

	for (auto _bullet = bullets.begin(); _bullet != bullets.end(); ++_bullet)
	{
		(*_bullet)->render(window);
	}

	window->display();
}