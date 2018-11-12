#include <Idle.h>
#include <Jumping.h>
#include <Climbing.h>
#include <Swording.h>
#include <Hammer.h>
#include <Shovel.h>
#include <Walk.h>

#include <string>

void Idle::handleInput() {}
void Idle::update() {}

void Idle::jumping(Animation* a)
{
	std::cout << "Idle -> Jumping" << std::endl;
	a->setCurrent(new Jumping());
	delete this;
}
void Idle::climbing(Animation* a)
{
	std::cout << "Idle -> Climbing" << std::endl;
	a->setCurrent(new Climbing());
	delete this;
}

void Idle::sword(Animation * a)
{
	std::cout << "Idle -> Swording" << std::endl;
	a->setCurrent(new Sword());
	delete this;
}

void Idle::hammer(Animation * a)
{
	std::cout << "Idle -> Hammering" << std::endl;
	a->setCurrent(new Hammering());
	delete this;
}

void Idle::shovel(Animation * a)
{
	std::cout << "Idle -> Shoveling" << std::endl;
	a->setCurrent(new Shovel());
	delete this;
}

void Idle::walk(Animation * a)
{
	std::cout << "Idle -> Walking" << std::endl;
	a->setCurrent(new Walking());
	delete this;
}
