#pragma once
#include <iostream>
#include <windows.h>
#include "BaseFileSystem.h"

typedef struct
{
	FileSystemOEMName OEMName;
	BYTE BytesPerSector[2];
	BYTE SectorsPerCluster[1];
	BYTE Padding2[23];
	long TotalSectors;

} NTFSBootRecord;


class NTFSFileSystem  :  
	public BaseFileSystem
{
public:
	NTFSFileSystem(FileReader* fileReader);
	~NTFSFileSystem();
private:
	void AssignBootRecordProperties(NTFSBootRecord* bootRecord);

};

