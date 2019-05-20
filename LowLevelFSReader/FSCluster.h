#pragma once
#include <iostream>
#include <windows.h>

using namespace std;

class FSCluster
{

private:
	BYTE * _Data;
	int _Size;

public:
	FSCluster(BYTE* data, int size) {
		_Data = data;
		_Size = size;
	};

	BYTE * GetData() {
		return _Data;
	};

	int GetSize() {
		return _Size;
	}

	void printHexData();

	~FSCluster();
};

