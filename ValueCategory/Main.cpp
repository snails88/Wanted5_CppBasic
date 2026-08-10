#include <iostream>
#include <string>
#include <memory>


class Actor
{
public:
	Actor(const char* newName)
	{
		size_t length = strlen(newName) + 1;
		name = new char[length] {};

		strcpy_s(name, length, newName);
	}
	~Actor()
	{
		if (name)
		{
			delete[] name;
			name = nullptr;
		}
	}

	// 복사 생성자
	Actor(const Actor& other)
	{
		if (name)
		{
			delete[] name;
			name = nullptr;
		}

		size_t length = strlen(other.name) + 1;
		name = new char[length] {};

		strcpy_s(name, length, other.name);
	}

	// 이동 생성자
	Actor(Actor&& other) noexcept	// other.name 에 nullptr 넣어서 const 안붙임
		//:name(other.name)
	{
		if (name)
		{
			delete[] name;
			name = nullptr;
		}
		name = other.name;

		other.name = nullptr;
	}

private:
	char* name = nullptr;
};

void Use(int& value)
{
	std::cout << "void Use(int& value)\n";
}

void Use(int&& value)
{
	std::cout << "void Use(int&& value)\n";
}

class Item
{

};

void Test(Item& item)
{
	std::cout << "void Test(Item& item)\n";
}

void Test(Item&& item)
{
	std::cout << "void Test(Item&& item)\n";
}

template<typename T>
void Function(T&& val)
{
	Test(std::forward<T>(val));
}

int main()
{
	int value = 10;
	Use(value);
	Use(std::move(value));

	Item item;
	Function(item);
	Function(Item());

	std::unique_ptr<Actor> actor1 = std::make_unique<Actor>("dd");
	std::unique_ptr<Actor> actor2 = std::move(actor1);

	// count는 L-Value : 메모리 차지, 식별가능, 변경 가능
	// 10 은 정수 리터럴로서 R-Value : 임시값.(L밸류특징의 반대)
	int count = 10;	

	// L-Value Reference
	int& lRef = count;
	//int& lRef2 = 10;	// 오류

	// R-Value Reference
	int&& rRef = 20;
	//int&& rRef2 = count;	// 오류


}