#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"
#include "Gun.h"
#include "Bullet.h"

class Player : public GameObject
{
public:
	Player(sf::Vector2f);
	~Player();

	void update(float) override;
	void render(Window*) override;
	Bullet* shoot();

	void addGun(Gun*);
	Gun* dropCurrentGun();

private:
	std::vector<Gun*> guns;
	Gun* currentGun;
};

#endif