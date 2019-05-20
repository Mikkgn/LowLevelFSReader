#include "pch.h"
#include "FileReader.h"

using namespace std;

FileReader::FileReader(string fileName)
{
	wstring wFileName(fileName.begin(), fileName.end());
	_fileHandle = CreateFileW(
		wFileName.c_str(),
		GENERIC_READ,
		FILE_SHARE_READ | FILE_SHARE_WRITE,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		NULL);

	if (_fileHandle == INVALID_HANDLE_VALUE)
	{
		throw exception("Some errors occurred while open file");
	}
}

BYTE* FileReader::GetData(int offset, int bufferSize) 
{
	LARGE_INTEGER offset_ = { offset };
	BOOL readFileResult = SetFilePointerEx(_fileHandle, offset_, nullptr, FILE_BEGIN);
	BYTE *buffer = new BYTE[bufferSize];
	DWORD read;
	readFileResult = ReadFile(_fileHandle, buffer, bufferSize, &read, nullptr);

	if (!readFileResult) {
		throw exception("Some errors occured while read file");
	}

	return buffer;
}


FileReader::~FileReader()
{
	CloseHandle(_fileHandle);
}
