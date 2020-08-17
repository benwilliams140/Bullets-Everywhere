#ifndef MOUSE_H
#define MOUSE_H

#include "GameObject.h"

class Mouse : public GameObject
{
public:
	Mouse(Window*);
	~Mouse();

	void update(float) override;

private:
};

#endif