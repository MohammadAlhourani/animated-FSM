#ifndef WALKING_H
#define WAlKING_H

#include <State.h>

class Walking : public State
{
public:
	Walking() {};
	~Walking() {};

	void idle(Animation* a);

};



#endif // !WALKING_H