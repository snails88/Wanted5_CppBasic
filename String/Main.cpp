#include <iostream>
//#include <Windows.h>
#include <string>

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

	const wchar_t* wcName = L"짱짱선재";

	//윈도우 타입
	//WCHAR

	std::string nameString = "선재";
	std::cout << nameString << "\n";
	std::cout << nameString.size() << "\n";
	// std::wstring // wchar_t

	//std::string을 C-Raw string으로
	const char* rawName = nameString.c_str();

	std::cout << "string length : " << length << "\n";
	std::cin.get();
}