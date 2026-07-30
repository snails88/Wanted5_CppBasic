#include <iostream>

class Entity
{
public:
	Entity() { std::cout << "Entity() called\n"; }
	virtual ~Entity() { std::cout << "~Entity() called\n"; }

public:
	virtual const char* GetName()
	{
		return "Entity";
	}
};

class Player : public Entity
{
public:
	//Player() {  }
	~Player() { std::cout << "~Player() called\n"; }

	Player(const char* inName)
	{
		std::cout << "Player() called\n";
		size_t length = strlen(inName) + 1;
		strcpy_s(name, length, inName);
	}
	
	virtual const char* GetName() override { return name; }
private:
	char name[15] = {};
};

int main()
{
	Entity* e1 = new Entity();
	Entity* e2 = new Player("선재");

	delete e1;
	e1 = nullptr;
	delete e2;
	e2 = nullptr;
}