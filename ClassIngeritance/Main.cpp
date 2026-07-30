#include <iostream>

class Base
{
public:
	Base()
	{
		std::cout << "Base() called\n";
	}
	~Base()
	{
		std::cout << "~Base() called\n";
	}

	void Play()
	{

	}
};

class Derived : public Base
{
public:
	Derived()
	{
		std::cout << "Derived() called\n";
	}
	~Derived()
	{
		std::cout << "~Derived() called\n";
	}

	void Attack()
	{

	}
};

int main()
{
	Derived derived;

	Base* b = new Derived();

	delete b;
	b = nullptr;
}