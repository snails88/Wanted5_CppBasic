#include <iostream>
#include <cstdio>

int main()
{
	FILE* file = nullptr;

	fopen_s(&file, "Test.txt", "rb");	// 파일 열기

	if (!file)
	{
		std::cout << "파일 열기 실패!\n";
		return 1;
	}

	std::cout << "파일 열기 성공\n";

	fclose(file);	// 파일 닫기
	file = nullptr;
}