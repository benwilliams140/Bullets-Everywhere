#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"

class Player : public GameObject
{
public:
	Player(sf::Vector2f);
	~Player();

	void update(float) override;
	
	void setDx(int);
	void setDy(int);

private:
	int dx, dy;
};

#endif