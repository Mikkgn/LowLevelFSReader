#pragma once
#include <iostream>
#include <string>
#include <windows.h>

#include "FSCluster.h"
#include "FileReader.h"

using namespace std;

typedef struct
{
	BYTE Padding1[3];
	char Name[8];
} FileSystemOEMName;


class BaseFileSystem
{
protected:
	
	FileReader* _FileReader;
	long long _ClustersCount;
	unsigned long long _SectorsCount;
	long long _BytesPerSector;
	long long _BytesPerCluster;
	long long _TotalBytes;
	FileSystemOEMName* _OEMName;

public:
	BaseFileSystem(FileReader* fileReader);
	long long GetClustersCount();
	void PrintSystemInfo();
	FSCluster* GetCluster(long clusterNumber);
	~BaseFileSystem();
};

