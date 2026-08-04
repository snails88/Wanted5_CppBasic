#include <iostream>
#include "CraftObject.h"

class Actor : public CraftObject
{
	TYPE_DECLARATIONS(Actor, CraftObject)
};

class Player : public Actor
{
	TYPE_DECLARATIONS(Player, Actor)
};

class Camera : public Actor
{
	TYPE_DECLARATIONS(Camera, Actor)
};

int main()
{
	std::shared_ptr<Actor> player = std::make_shared<Player>();
	std::shared_ptr<Player> targetPlayer = Cast<Player>(player);
}

//#define TO_NAME(x) #x
//#define CLASS_NAME(type)					\
//	public:									\
//	virtual const char* ClassName() const	\
//	{										\
//		return TO_NAME(type);				\
//	}										\

//class Actor
//{
//	CLASS_NAME(Actor)
////public: virtual const char* ClassName() const {
////	return "Actor";
////};
//public:
//	static size_t TypeId()
//	{
//		static int runTimeTypeId = 0;
//		return reinterpret_cast<size_t>(&runTimeTypeId);
//	}
//
//	//virtual const char* ClassName() const 
//	//{
//	//	//return "Actor"; 
//	//	return TO_NAME(Actor);
//	//}
//};
//
//class Player : public Actor
//{
//	CLASS_NAME(Player)
//public:
//	static size_t TypeId()
//	{
//		static int runTimeTypeId = 0;
//		return reinterpret_cast<size_t>(&runTimeTypeId);
//	}
//
//private:
//	//virtual const char* ClassName() const override 
//	//{
//	//	return TO_NAME(Player);
//	//	//return "Player"; 
//	//}
//};

//int main()
//{
//	Actor* actor = new Actor();
//	Actor* player = new Player();
//
//	std::cout << actor->ClassName() << "\n";
//	std::cout << player->ClassName() << "\n";
//
//	//if (strcmp(actor->ClassName(), player->ClassName()) == 0)
//	//{
//	//	std::cout << "같은 타입\n";
//	//}
//	//else
//	//{
//	//	std::cout << "다른 타입\n";
//	//}
//
//	if (actor->TypeId() == player->TypeId())
//	{
//		std::cout << "같은 타입\n";
//	}
//	else
//	{
//		std::cout << "다른 타입";
//	}
//
//	delete actor;
//	actor = nullptr;
//	delete player;
//	player = nullptr;
//}