#ifndef PLAYER_H
#define PLAYER_H

#include <Input.h>
#include <Animation.h>
#include <AnimatedSprite.h>

class Player
{
private:
	Animation m_animation;
	AnimatedSprite Idling;
	AnimatedSprite jump;

	Player();

public:
	Player(const AnimatedSprite& , const AnimatedSprite&);
	~Player();


	AnimatedSprite& getAnimatedSprite(); 

	bool Jump = false;

	void handleInput(Input);
	void update();
};

#endif // !PLAYER_H
