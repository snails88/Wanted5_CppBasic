#include <iostream>

void PrintArray(int* array, int count)
{
	for (int i = 0; i < count; i++)
	{
		std::cout << array[i] << " ";
	}
}

int main()
{
	const int length = 5;
	int array[length];
	memset(array, 0, sizeof(int) * length);

	int* ptr = array;

	int* dArray = new int[length];


	*(ptr + 2) = 30;

	for (int ix = 0; ix < length; ix++)
	{
		array[ix] = ix + 1;
		
	}

	for (const int value : array)
	{
		std::cout << value << " ";
	}

	PrintArray(array, length);

	//std::cout << array[ix] << " ";

	delete[] dArray;

	std::cin.get();
}