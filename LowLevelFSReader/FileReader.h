#pragma once
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

class FileReader
{
private:
	HANDLE _fileHandle;

public:
	FileReader(string fileName);

	BYTE* GetData(int offset, int bufferSize);

	~FileReader();
};

