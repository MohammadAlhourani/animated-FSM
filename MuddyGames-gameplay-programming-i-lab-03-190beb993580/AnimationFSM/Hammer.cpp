#include "Hammer.h"
#include "Idle.h"

void Hammering::idle(Animation * a)
{
	std::cout << "Hamering -> Idle " << std::endl;
	a->setCurrent(new Idle());
	delete this;
}
