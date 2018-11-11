#include <iostream>
#include <Player.h>
#include <Idle.h>
#include <Debug.h>

Player::Player()
{
	m_animation.setCurrent(new Idle());
	m_animation.setPrevious(new Idle());
}

Player::Player(const AnimatedSprite& s ,  const AnimatedSprite& j, const AnimatedSprite& c, const AnimatedSprite& a, const AnimatedSprite& h, const AnimatedSprite& sh, const AnimatedSprite& w)
	: Idling(s) , jump(j) , Climb(c), Sword(a), Hammer(h), Shovel(sh), Walk(w)
{
	m_animation.setCurrent(new Idle());
	m_animation.setPrevious(new Idle());
}

Player::~Player() {}

AnimatedSprite& Player::getAnimatedSprite()
{
	if (idle)
	{
		int frame = Idling.getCurrentFrame();
		Idling.setTextureRect(Idling.getFrame(frame));
		return Idling;
	}
	else if (Jump)
	{
		int frame = jump.getCurrentFrame();
		jump.setTextureRect(jump.getFrame(frame));
		return jump;
	}
	else if (climb)
	{
		int frame = Climb.getCurrentFrame();
		Climb.setTextureRect(Climb.getFrame(frame));
		return Climb;
	}
	else if (sword)
	{
		int frame = Sword.getCurrentFrame();
		Sword.setTextureRect(Sword.getFrame(frame));
		return Sword;
	}
	else if(hammer)
	{
		int frame = Hammer.getCurrentFrame();
		Hammer.setTextureRect(Hammer.getFrame(frame));
		return Hammer;
	}
	else if (shovel)
	{
		int frame = Shovel.getCurrentFrame();
		Shovel.setTextureRect(Shovel.getFrame(frame));
		return Shovel;
	}
	else
	{
		int frame = Walk.getCurrentFrame();
		Walk.setTextureRect(Walk.getFrame(frame));
		return Walk;
	}
}

void Player::handleInput(Input in)
{
	DEBUG_MSG("Handle Input");

	switch (in.getCurrent())
	{
	case Input::Action::IDLE:	
		idle = true;
		Jump = false;
		climb = false;
		sword = false;
		hammer = false;
		shovel = false;
		walk = false;
		m_animation.idle();
		break;
	case Input::Action::CLIMB:	
		idle = false;
		climb = true;
		Jump = false;
		sword = false;
		hammer = false;
		shovel = false;
		walk = false;
		m_animation.climbing();
		break;
	case Input::Action::JUMP:	
		idle = false;
		climb = false;
		Jump = true;
		sword = false;
		hammer = false;
		shovel = false;
		walk = false;
		m_animation.jumping();
		break;
	case Input::Action::HAMMER:
		idle = false;
		climb = false;
		Jump = false;
		sword = false;
		hammer = true;
		shovel = false;
		walk = false;
	//	m_animation.();
		break;
	case Input::Action::SWORD:
		idle = false;
		climb = false;
		Jump = false;
		sword = true;
		hammer = false;
		shovel = false;
		walk = false;
		m_animation.swording();
		break;
	case Input::Action::SHOVEL:
		idle = false;
		climb = false;
		Jump = false;
		sword = false;
		hammer = false;
		shovel = true;
		walk = false;
		//m_animation.();
		break;
	case Input::Action::WALK:
		idle = false;
		climb = false;
		Jump = false;
		sword = false;
		hammer = false;
		shovel = false;
		walk = true;
		//m_animation.();
		break;
	default:
		break;
	}
}

void Player::update()
{
	Idling.update();
	jump.update();
	Climb.update();
	Sword.update();
	Hammer.update();
	Shovel.update();
	Walk.update();
}

