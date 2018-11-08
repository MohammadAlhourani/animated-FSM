#ifndef SWORD_H
#define SWORD_H

#include <State.h>

class Sword : public State
{
public:
	Sword() {};
	~Sword() {};

	void jumping(Animation* a);
	void idle(Animation* a);

};
#endif // !SWORD_H