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
	AnimatedSprite Climb;
	AnimatedSprite Sword;

	Player();

public:
	Player(const AnimatedSprite& , const AnimatedSprite&, const AnimatedSprite&, const AnimatedSprite&);
	~Player();


	AnimatedSprite& getAnimatedSprite(); 

	bool idle = true;
	bool Jump = false;
	bool climb = false;
	bool sword = false;

	void handleInput(Input);
	void update();
};

#endif // !PLAYER_H
