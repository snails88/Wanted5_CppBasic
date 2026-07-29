#pragma once

//#include "Weapon.h"

class Weapon;

class Player
{
public:
	Player();
	~Player();

private:
	Weapon* weapon = nullptr;

};

