#ifndef STATE_H
#define STATE_H

#include <iostream>
#include <typeinfo>

#include <Input.h>
#include <Animation.h>
#include <Debug.h>

class State
{
public:
	virtual void handleInput() {}

	virtual void update() {}

	virtual void idle(Animation* a)
	{
		DEBUG_MSG("State::Idling");
	}
	virtual void jumping(Animation* a)
	{
		DEBUG_MSG("State::Jumping");
	}
	virtual void climbing(Animation* a)
	{
		DEBUG_MSG("State::Climbing");
	}
	virtual void sword(Animation* a)
	{
		DEBUG_MSG("State::Swording");
	}
	virtual void hammer(Animation* a)
	{
		DEBUG_MSG("State::Hammering");
	}
	virtual void shovel(Animation* a)
	{
		DEBUG_MSG("State::Shoveling");
	}
	virtual void walk(Animation* a)
	{
		DEBUG_MSG("State::Walking");
	}

};

#endif // ! ANIMATION_H

