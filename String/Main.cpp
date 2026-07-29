#include <iostream>

class Player
{
public:
	Player(const char* name)
	{
		size_t length = strlen(name) + 1;
		this->name = new char[length];

		strcpy_s(this->name, length, name);

		//for (size_t i = 0; i < length - 1; i++)
		//{
		//	this->name[i] = name[i];
		//}
		//this->name[length - 1] = '\0';
	}
	~Player()
	{
		if (name)
		{
			delete[] name;
		}
	}

	void PrintName() const
	{
		std::cout << name << "\n";
	}

private:
	char* name = nullptr;
};

int main()
{
	Player player("지존선재짱");
	player.PrintName();

	const char* name = "선재짱짱맨";

	size_t length = strlen(name);

	std::cout << "string length : " << length << "\n";
	std::cin.get();
}