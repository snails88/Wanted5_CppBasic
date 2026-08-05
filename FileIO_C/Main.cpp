#include <iostream>
#include <cstdio>
#include <cassert>

void CreateConfigFile(const char* filename)
{
	float framerate = 120.f;
	int width = 30;
	int height = 20;

	const int length = 256;
	char string[length] = {};

	sprintf_s(string, length, "framerate = %.2f\nwidth = %d\nheight = %d\n", framerate, width, height);

	FILE* configFile = nullptr;
	fopen_s(&configFile, filename, "wt");
	if (!configFile)
	{
		return;
	}

	fwrite(string, sizeof(char), strlen(string) + 1, configFile);

	fclose(configFile);
	configFile = nullptr;
}

int main()
{
	const char* configFileName = "Setting.txt";
	CreateConfigFile(configFileName);

	FILE* configFile = nullptr;
	fopen_s(&configFile, configFileName, "rt");
	if (!configFile)
	{
		return 1;
	}

	fseek(configFile, 0, SEEK_END);	// 파일 끝으로 이동
	int fileSize = static_cast<int>(ftell(configFile));

	//fseek(configFile, 0, SEEK_SET);	// 다시 처음위치로 이동
	rewind(configFile);					// 처음위치로 이동(위랑 같은역할)

	char* configData = new char[fileSize];
	memset(configData, 0, sizeof(char) * fileSize);

	size_t readSize = fread(configData, sizeof(char), fileSize, configFile);

	float framerate = 0.f;
	int width = 0;
	int height = 0;

	sscanf_s(configData, "framerate = %f\nwidth = %d\nheight = %d\n", &framerate, &width, &height);
	

	delete[] configData;
	configData = nullptr;

	FILE* file = nullptr;

	fclose(configFile);
	configFile = nullptr;

	//fopen_s(&file, "Test.txt", "rb");	// 파일 열기

	//if (!file)
	//{
	//	std::cout << "파일 열기 실패!\n";
	//	return 1;
	//}

	

	//const char* message = "C 라이브러리로 기록한 텍스트\n";

	//if (fputs(message, file) == EOF)
	//{
	//	std::cout << "파일 쓰기 실패\n";
	//	fclose(file);
	//	return 1;
	//}

	//const int size = 256;
	//char buf[size] = {};
	////fgets(buf, size, file);

	//size_t readSize = fread(buf, 1, size, file);
	//std::cout << buf << "\n readSize : " << readSize;

	//FILE* copyFile = nullptr;
	//errno_t errCode = fopen_s(&copyFile, "Test2.txt", "wb");

	//if (!copyFile)
	//	return 1;

	//size_t writtenSize = fwrite(buf, sizeof(char), readSize, copyFile);

	//assert(readSize == writtenSize);

	////std::cout << "파일 열기 성공\n";

	//fclose(file);	// 파일 닫기
	//fclose(copyFile);
	//file = nullptr;
	//copyFile = nullptr;
}