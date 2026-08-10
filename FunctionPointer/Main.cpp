#include <iostream>

void Test()
{
	std::cout << "Test()\n";

	
}

float Add(float a, float b)
{
	return a + b;
}

float Multiply(float a, float b)
{
	return a * b;
}

typedef bool (*Comparer)(int, int);	// 함수 포인터를 타입으로 선언(Comparer가 타입이됨)
//using Comparer = bool (*)(int, int);	// 위랑 같음

void BubbleSort(int* array, int length, Comparer comparer /*bool (*Comparer)(int, int)*/)
{
	for (int i = 0; i < length - 1; i++)
	{
		for (int j = 0; j < length - 1 - i; j++)
		{
			//if (array[j] < array[j + 1])		// 부호 바꿔서 오름/내림차순 변경
			if(comparer(array[j], array[j + 1]))
			{
				std::swap(array[j], array[j + 1]);
			}
		}
	}
}

bool Ascending(int a, int b)
{
	return a > b;
}

bool Descending(int a, int b)
{
	return a < b;
}



class Actor
{
public:
	void Tick(float deltaTime) {}
};

void (Actor::* ActorTick)(float);

int main()
{
	//ActorTick = Actor::Tick;

	int array[] = { 5,8,1,4,65,43,22 };
	int length = sizeof(array) / sizeof(array[0]);

	BubbleSort(array, length, Descending);

	std::cin.get();

	//void (*FunctionPointer)() = nullptr;	// 함수 포인터

	//FunctionPointer = Test;	// FunctionPointer = &Test; 이거도 똑같음
	//
	//if(FunctionPointer)
	//	FunctionPointer();
	//Test();

	//float (*Calculator)(float a, float b) = Add;	// float (*Calculator)(float, float)	// a b 빼도됨

	//float result = Calculator(10.f, 25.f);

	//std::cout << "result: " << result << "\n";

	//Calculator = Multiply;

	//result = Calculator(10.f, 25.f);

	//std::cout << "result: " << result << "\n";
}