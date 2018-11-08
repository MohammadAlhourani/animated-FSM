#include <iostream>
#include <Player.h>
#include <Idle.h>
#include <Debug.h>

Player::Player()
{
	m_animation.setCurrent(new Idle());
	m_animation.setPrevious(new Idle());
}

Player::Player(const AnimatedSprite& s ,  const AnimatedSprite& j, const AnimatedSprite& c, const AnimatedSprite& a) : Idling(s) , jump(j) , Climb(c),Sword(a)
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
		m_animation.idle();
		break;
	case Input::Action::UP:	
		idle = false;
		climb = true;
		Jump = false;
		m_animation.climbing();
		break;
	case Input::Action::LEFT:	
		idle = false;
		climb = false;
		Jump = true;
		m_animation.jumping();
		break;
	case Input::Action::RIGHT:
		idle = false;
		climb = false;
		Jump = true;
		m_animation.jumping();
		break;
	case Input::Action::SWORD:
		idle = false;
		climb = false;
		Jump = false;
		sword = true;
		m_animation.swording();
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
}


