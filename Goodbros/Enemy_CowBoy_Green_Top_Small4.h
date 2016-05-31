#ifndef __ENEMY_COWBOY_GREEN_TOP_SMALL4_H__
#define __ENEMY_COWBOY_GREEN_TOP_SMALL4_H__

#include "Enemy.h"

class Enemy_CowBoy_Green_Top_Small4 : public Enemy
{
private:
	bool going_forward = true;
	bool stop = false;

	Animation forward;
	Animation backward;
	Animation dieshot;
	Animation dieexplotion;
	Animation shoot;
	Animation fwtumble;
	Animation grenadeSm;;
	Animation jumpSm;
	Animation spawnn;
	Animation spawnup;
	Animation spawndown;
	bool isdead = false;

	iPoint original_pos;
public:

	Enemy_CowBoy_Green_Top_Small4(float x, float y);
	void Die();
	void Move();
};

#endif //  __ENEMY_COWBOY_GREEN_TOP_FABTEN_2_H__