#include <iostream>

class Player
{
	friend class Manager;
public:
	Player() = default;
	~Player() = default;

	void SetXY(int newX, int newY)
	{
		x = newX;
		y = newY;
	}

	friend void SetPosition(Player& player, int newX, int newY);

private:
	int x = 0;
	int y = 0;
};


void SetPosition(Player& player, int newX, int newY)
{
	player.x = newX;
	player.y = newY;
}


class Manager
{
public:
	Manager(Player* const newPlayer)
		: player(newPlayer)
	{

	}

	void Test()
	{
		player->x = 30;
		player->y = 60;
	}

private:
	Player* player = nullptr;
};

int main()
{
	const int length = 5;
	Player* players[length] = {};

	for (int i = 0; i < length; i++)
	{
		players[i] = new Player();
	}

	SetPosition(*players[0], 3, 5);

	Manager manager(players[1]);
	manager.Test();


	for (Player*& player : players)
	{
		delete player;
		player = nullptr;
	}

	std::cin.get();
}