#include <iostream>

void Release(int** t)
{
	if (t != nullptr)
	{
		delete *t;
		*t = nullptr;
	}
}

void Swap(int* const a, int* const b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void SwapRef(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

int main()
{
	int numberA = 10;
	int numberB = 20;
	//Swap(&numberA, &numberB);

	SwapRef(numberA, numberB);

	int var = 8;
	int* ptr = &var;

	int* testPtr = new int;
	Release(&testPtr);

	//delete testPtr;
	//testPtr = nullptr;

	const int length = 100;
	int* buffer = new int[length];
	int** bufferPtr = &buffer;

	memset(buffer, 0, sizeof(int) * length);

	delete[] buffer;

	std::cin.get();
}