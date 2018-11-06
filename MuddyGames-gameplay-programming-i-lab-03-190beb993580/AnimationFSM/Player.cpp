#include <iostream>
#include <Player.h>
#include <Idle.h>
#include <Debug.h>

Player::Player()
{
	m_animation.setCurrent(new Idle());
	m_animation.setPrevious(new Idle());
}

Player::Player(const AnimatedSprite& s ,  const AnimatedSprite& t) : Idling(s) , jump(t)
{
	m_animation.setCurrent(new Idle());
	m_animation.setPrevious(new Idle());
}

Player::~Player() {}

AnimatedSprite& Player::getAnimatedSprite()
{
	if (Jump == false)
	{
		int frame = Idling.getCurrentFrame();
		Idling.setTextureRect(Idling.getFrame(frame));
		return Idling;
	}
	else
	{
		int frame = jump.getCurrentFrame();
		jump.setTextureRect(jump.getFrame(frame));
		return jump;
	}
}

void Player::handleInput(Input in)
{
	DEBUG_MSG("Handle Input");

	switch (in.getCurrent())
	{
	case Input::Action::IDLE:	
		Jump = false;
		m_animation.idle();
		break;
	case Input::Action::UP:	
		m_animation.climbing();
		break;
	case Input::Action::LEFT:	
		Jump = true;
		m_animation.jumping();
		break;
	case Input::Action::RIGHT:
		Jump = true;
		m_animation.jumping();
		break;
	default:
		break;
	}
}

void Player::update()
{
	Idling.update();
	jump.update();
}


