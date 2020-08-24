#ifndef GAME_H
#define GAME_H

#include "Window.h"
#include "Mouse.h"
#include "Player.h"
#include "Gun.h"
#include "Bullet.h"

const std::string windowTitle = "Bullets Everywhere";
const unsigned int windowWidth = 1024;
const unsigned int windowHeight = 768;
const unsigned int frameLimit = 60;

enum class State
{
	RUNNING,
	PAUSED,
	EXIT
};

class Game
{
public:
	Game();
	~Game();

	void run();

private: 
	void processInput();
	void update(float);
	void render();

	float totalTimeElapsed;

	Window* window;
	Mouse* mouse;
	State state;

	Player* player;

	std::vector<Bullet*> bullets;
};

#endif