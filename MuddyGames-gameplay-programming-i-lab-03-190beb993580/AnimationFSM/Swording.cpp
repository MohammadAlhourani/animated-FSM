#include "Swording.h"
#include "Jumping.h"
#include "Idle.h"


void Sword::jumping(Animation * a)
{
	std::cout << "swording -> jumping " << std::endl;
	a->setCurrent(new Jumping());
	delete this;
}

void Sword::idle(Animation * a)
{
	std::cout << "Sword -> Idle" << std::endl;
	a->setCurrent(new Idle());
	delete this;
}


