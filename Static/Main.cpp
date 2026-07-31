#include <iostream>
#include "File1.h"
#include "File2.h"
#include "Person.h"

void Increment()
{
	static int count = 0;
	++count;
	std::cout << "Count : " << count << std::endl;
}




class Person
{
public:
	Person()
	{
		++personCount;
		std::cout << personCount << "번째 Person 객체 생성\n";
	}

	~Person()
	{
		--personCount;
	}

private:
	inline static int personCount = 0;
};

//int Person::personCount = 0;

int main()
{
	//FileOneFunction();
	//FileTwoFunction();
	//Increment();
	//Increment();
	//Increment();

	Person p1;
	Person p2;
}