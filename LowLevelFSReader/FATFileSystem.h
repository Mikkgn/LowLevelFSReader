#pragma once
#include "BaseFileSystem.h"

typedef struct
{
	FileSystemOEMName OEMName;
	BYTE BytesPerSector[2];
	BYTE SectorsPerCluster;
	BYTE ReservedSectorsCount[2];
	BYTE NumbersOfFat;
	BYTE RootEntityCount[2];
	BYTE TotalSectors16[2];
	BYTE Padding2[1];
	BYTE FatSize16[2];
	BYTE Padding3[8];
	BYTE TotalSectors32[4];
	BYTE FatSize32[4];

} FATBootRecord;

class FATFileSystem :
	public BaseFileSystem
{
public:
	FATFileSystem(FileReader* fileReader);
	~FATFileSystem();
private:
	void AssignBootRecordProperties(FATBootRecord* bootRecord);
};

