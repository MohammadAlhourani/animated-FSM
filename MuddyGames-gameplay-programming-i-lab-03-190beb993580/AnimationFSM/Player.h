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
	AnimatedSprite Hammer;
	AnimatedSprite Shovel;
	AnimatedSprite Walk;

	Player();

public:
	Player(const AnimatedSprite& , const AnimatedSprite&, const AnimatedSprite&, const AnimatedSprite&, const AnimatedSprite&, const AnimatedSprite&, const AnimatedSprite&);
	~Player();


	AnimatedSprite& getAnimatedSprite(); 

	bool idle = true;
	bool Jump = false;
	bool climb = false;
	bool sword = false;
	bool hammer = false;
	bool shovel = false;
	bool walk = false;

	void handleInput(Input);
	void update();
};

#endif // !PLAYER_H
