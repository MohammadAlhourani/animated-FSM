#ifndef SHOVELING_H
#define SHOVELING_H

#include <State.h>

class Shovel : public State
{
public:
	Shovel() {};
	~Shovel() {};

	void idle(Animation* a);

};


#endif // !SHOVELING_H