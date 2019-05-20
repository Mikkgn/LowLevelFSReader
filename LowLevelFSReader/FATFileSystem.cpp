#include "pch.h"
#include "FATFileSystem.h"


FATFileSystem::FATFileSystem(FileReader* fileReader):BaseFileSystem(fileReader)
{
	FATBootRecord *bootRecord = (FATBootRecord*)_FileReader->GetData(0, 1024);
	AssignBootRecordProperties(bootRecord);

}

void FATFileSystem::AssignBootRecordProperties(FATBootRecord* bootRecord)
{
	_OEMName = &bootRecord->OEMName;
	_BytesPerSector = *(unsigned short*)bootRecord->BytesPerSector;

	int fatStartSector = *(unsigned short*)bootRecord->ReservedSectorsCount;
	int totalSectors16 = *(unsigned short*)bootRecord->TotalSectors16;
	long totalSectors32 = *(long*)bootRecord->TotalSectors32;
	int fatSize16 = *(unsigned short*)bootRecord->FatSize16;
	long fatSize32 = *(long*)bootRecord->FatSize32;
	long fatSectors = (int)bootRecord->NumbersOfFat * (fatSize16 != 0 ? fatSize16 : fatSize32);
	long rootDirectoryStartSector = fatStartSector + fatSectors;
	long rootEntityCount = *(unsigned short*)bootRecord->RootEntityCount;
	long rootDirectorySectors = (32 * rootEntityCount + _BytesPerSector - 1) / _BytesPerSector;
	long dataStartSector = rootDirectorySectors + rootDirectoryStartSector;
	long dataSectorsCount = (totalSectors16 != 0 ? totalSectors16 : totalSectors32) - dataStartSector;

	int sectorsPerCluster = (unsigned short)bootRecord->SectorsPerCluster;
	_ClustersCount = dataSectorsCount / sectorsPerCluster;
	
	_BytesPerCluster = _BytesPerSector * sectorsPerCluster;
	_SectorsCount = totalSectors16 != 0 ? totalSectors16 : totalSectors32;
	_TotalBytes = (long long)_BytesPerSector * (long long)_SectorsCount;
}


FATFileSystem::~FATFileSystem()
{
}
