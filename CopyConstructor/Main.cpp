#include <iostream>

#include "Player.h"

int main()
{
	Player player1;
	Player player2("선재짱");
	Player player3(player2);
	Player player4;
	player4 = player3;

	std::cin.get();
}