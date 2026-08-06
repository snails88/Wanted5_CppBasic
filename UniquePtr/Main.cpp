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
	Player()
	{
		std::cout << "Player Constructed.\n";
	}

	~Player()
	{
		std::cout << "Player Destroyed.\n";
	}

	void Attack() const
	{
		std::cout << "Player Attack.\n";
	}
};

void AttackPlayer(const Player* const player)
{
	player->Attack();
}

// 레퍼런스로하면 delete를 못하기때문에 좀 더 권장됨
void AttackPlayer2(const Player& player)
{
	player.Attack();
}

void AttackPlayer3(const std::unique_ptr<Player>& player)
{
	player->Attack();
}

int main()
{
	//Player* player = new Player();
	//delete player;
	//player = nullptr;

	std::unique_ptr<Player> player = std::make_unique<Player>();
	player->Attack();

	AttackPlayer(player.get());	// 원시포인터 전달. delete할 수 있어서 위험
	AttackPlayer2(*player);		// 레퍼런스로 전달 원시포인터보단 안전(delete안됨)
	AttackPlayer3(player);		// 스마트 포인터의 레퍼런스 사용. unique_ptr의 정의/사용 방식에는 위배됨

	std::unique_ptr<Player> otherPlayer = std::move(player);	// 소유권이전. 이후로는 player는 사용하면안됨
	player.reset();	// 이전한뒤로는 포인터를 리셋해주는게 좋음(nullptr 들어감)
	

	//std::unique_ptr<Player> player2 = player;	// 대입/복사생성자 막아놔서 안됨.
	//Player* player2 = player.get();	// 원시포인터받기(delete하면안됨.위험)
	
}