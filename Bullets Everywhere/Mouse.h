#ifndef MOUSE_H
#define MOUSE_H

#include "Window.h"
#include "GameObject.h"

const std::string fileName = "./assets/target.png";

class Mouse : public GameObject
{
public:
	Mouse(Window*);
	~Mouse();

	void update(float) override;

private:
	
};

#endif