#include "pch.h"
#include "BaseFileSystem.h"



BaseFileSystem::BaseFileSystem(FileReader* fileReader)
{
	_FileReader = fileReader;
}


long long BaseFileSystem::GetClustersCount() {
	return _ClustersCount;
}

FSCluster * BaseFileSystem::GetCluster(long clusterNumber)
{
	long long dataOffset = (clusterNumber - 1) * _BytesPerCluster;
	BYTE* data = _FileReader->GetData(dataOffset, _BytesPerCluster);
	return new FSCluster(data, _BytesPerCluster);
}


void BaseFileSystem::PrintSystemInfo()
{
	cout << "Selected file system OEM name: " << _OEMName->Name << endl;
	cout << "Selected file system properties:" << endl;
	cout << "Total sectors: " << _SectorsCount << endl;
	cout << "Total clusters: " << _ClustersCount << endl;
	cout << "Bytes per sector: " << _BytesPerSector << endl;
	cout << "Bytes per cluster: " << _BytesPerCluster << endl;
	cout << "Total bytes: " << _TotalBytes << endl;
}


BaseFileSystem::~BaseFileSystem()
{
}
