#include "pch.h"
#include "ExFATFileSystem.h"


ExFATFileSystem::ExFATFileSystem(FileReader* fileReader): BaseFileSystem(fileReader)
{
	ExFATBootRecord *bootRecord = (ExFATBootRecord*)_FileReader->GetData(0, 1024);
	AssignBootRecordProperties(bootRecord);
}


ExFATFileSystem::~ExFATFileSystem()
{
}

void ExFATFileSystem::AssignBootRecordProperties(ExFATBootRecord* bootRecord)
{
	_OEMName = &bootRecord->OEMName;
	_SectorsCount = *(unsigned long long*)bootRecord->VolumeLength;
	_BytesPerSector = (long long)pow(2, (int)bootRecord->BytesPerSectorShift);
	long long sectorsPerCluster = pow(2, (int)bootRecord->SectorsPerClusterShift);
	_BytesPerCluster = _BytesPerSector * sectorsPerCluster;
	_ClustersCount = *(long*)bootRecord->ClustersCount;
	_TotalBytes = (long long)_BytesPerSector * _SectorsCount;
}

