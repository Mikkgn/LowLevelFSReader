#pragma once
#include "BaseFileSystem.h"
typedef struct
{
	FileSystemOEMName OEMName;
	BYTE Padding1[61];
	BYTE VolumeLength[8];
	BYTE FatOffset[4];
	BYTE FatLength[4];
	BYTE ClusterHeapOffset[4];
	BYTE ClustersCount[4];
	BYTE FirstClusterOfRootDirectory[4];
	BYTE Padding2[8];
	BYTE BytesPerSectorShift;
	BYTE SectorsPerClusterShift;
	BYTE NumberOfFats;

} ExFATBootRecord;

class ExFATFileSystem: public BaseFileSystem
{
public:
	ExFATFileSystem(FileReader* fileReader);
	~ExFATFileSystem();
private:
	void AssignBootRecordProperties(ExFATBootRecord* bootRecord);
};

