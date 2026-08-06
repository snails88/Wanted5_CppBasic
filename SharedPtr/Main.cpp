#include <iostream>
#include <memory>

class Actor
{
public:
	virtual ~Actor() = default;
};

class Player : public Actor
{
public:
	virtual ~Player()
	{
		std::cout << "꿱\n";
	}
};

int main()
{
	std::shared_ptr<Actor> actor = std::make_shared<Actor>();
	std::shared_ptr<Player> player = std::make_shared<Player>();
	std::shared_ptr<Player> otherPlayer = player;
}