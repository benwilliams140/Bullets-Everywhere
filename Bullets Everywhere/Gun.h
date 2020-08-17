#ifndef GUN_H
#define GUN_H

#include "GameObject.h"
#include "Player.h"
#include "Mouse.h"
#include "Window.h"

class Gun : public GameObject
{
public:
	Gun(Player*, Mouse*);
	~Gun();

	void update(float) override;

private:
	Player* player;
	Mouse* mouse;
};

#endif