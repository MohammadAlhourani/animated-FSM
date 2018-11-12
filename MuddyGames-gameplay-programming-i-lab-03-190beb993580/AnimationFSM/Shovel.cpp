#include "Shovel.h"
#include "Idle.h"

void Shovel::idle(Animation * a)
{
	std::cout << "Shoveling -> Idle" << std::endl;
	a->setCurrent(new Idle());
	delete this;
}
