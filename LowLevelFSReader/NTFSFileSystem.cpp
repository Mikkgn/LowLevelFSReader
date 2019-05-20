#include "pch.h"
#include "NTFSFileSystem.h"


NTFSFileSystem::NTFSFileSystem(FileReader* fileReader): BaseFileSystem(fileReader)
{
	NTFSBootRecord *bootRecord = (NTFSBootRecord*)_FileReader->GetData(0, 1024);
	AssignBootRecordProperties(bootRecord);

}


void NTFSFileSystem::AssignBootRecordProperties(NTFSBootRecord* bootRecord) {
	_OEMName = &bootRecord->OEMName;
	_BytesPerSector = *(unsigned short*)bootRecord->BytesPerSector;
	int sectorsPerCluster = *(unsigned short*)bootRecord->SectorsPerCluster;
	_BytesPerCluster = _BytesPerSector * sectorsPerCluster;
	_SectorsCount = bootRecord->TotalSectors;
	_ClustersCount = _SectorsCount / sectorsPerCluster;
	_TotalBytes = (long long)_BytesPerSector * (long long)_SectorsCount;
}


NTFSFileSystem::~NTFSFileSystem()
{
}
