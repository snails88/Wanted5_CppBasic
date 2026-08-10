#include <vector>
#include <algorithm>
#include <iostream>


struct Greater
{
	bool operator()(int left, int right)
	{
		return left > right;
	}
};

struct Less
{
	bool operator()(int left, int right)
	{
		return left < right;
	}
};

int main()
{
	std::vector<int> data = { 1,5,9,7,5,6,1,23,54,6,5 };

	Greater greater;
	std::sort(data.begin(), data.end(), Less());

	int result = 0;
	auto add = [&result](int value)
		{
			result += value;
		};

	add(10);
	add(20);

	std::cout << "result : " << result << "\n";

	for (const int item : data)
	{
		std::cout << item << " ";
	}

	std::cout << "\n";
}