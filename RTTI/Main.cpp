#include <iostream>

class Actor
{
	public:
		virtual ~Actor() = default;

};

class Camera : public Actor
{

};

class Player : public Actor
{

};


int main()
{
	Actor* actor1 = new Player();
	Actor* actor2 = new Camera();

	Player* player = dynamic_cast<Player*>(actor1);
	if (player)
	{
		std::cout << "Player 형변환 성공\n";
	}

	const type_info& typeInfo1 = typeid(*actor1);
	const type_info& typeInfoPlayer = typeid(Player);
	const type_info& typeInfo2 = typeid(*actor2);

	if (typeInfo1 == typeInfoPlayer)
	{
		std::cout << "actor1은 " << typeInfo1.name() <<"타입\n";
	}
}