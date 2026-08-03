#include <iostream>

template<typename T>
void Swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

template<typename T, int size = 10>
class Data
{
public:
	Data(const T& newData)
		:data(newData)
private:
	T data = {};

	T GetData() const { return data; }
	void SetData(const T& newData) { data = newData; }
	int GetSize() { return size; }
};


int main()
{
	int a = 10;
	int b = 30;

	Swap<int>(a, b);

	Data<int, 100> intData(30);
	Data<float> pi(3.141592f);

	std::swap<int>(a, b);

	std::cin.get();
}