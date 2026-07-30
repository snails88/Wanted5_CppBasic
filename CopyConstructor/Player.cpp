#include "Player.h"

Player::Player()
{
	std::cout << "Player() called\n";
}

Player::Player(const char* inName)
{
	size_t length = strlen(inName) + 1;
	name = new char[length] {};
	strcpy_s(name, length, inName);

	std::cout << "Player(const char* inName) called\n";
}

Player::Player(const Player& other)
{
	size_t length = strlen(other.name) + 1;

	name = new char[length] {};

	strcpy_s(name, length, other.name);

	std::cout << "Player(const Player& other) called\n";
}

Player::~Player()
{
	if (name)
	{
		delete[] name;
		name = nullptr;
	}
}

Player& Player::operator=(const Player& other)
{
	// 복사 처리
	size_t length = strlen(other.name) + 1;
	name = new char[length] {};
	strcpy_s(name, length, other.name);

	std::cout << "Player& Player::operator=(const Player& other) called\n";

	return *this;
}
