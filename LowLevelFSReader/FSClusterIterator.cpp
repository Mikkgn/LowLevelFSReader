#include "pch.h"
#include "FSClusterIterator.h"


FSClusterIterator::FSClusterIterator(BaseFileSystem* fileSystem):BaseIterator()
{
	_FileSystem = fileSystem;
	_CurrentIndex = 0;
}


void FSClusterIterator::First()
{
	_CurrentIndex = 0;
}

void FSClusterIterator::Next()
{
	_CurrentIndex++;
}

bool FSClusterIterator::IsDone()
{
	return _CurrentIndex == (_FileSystem->GetClustersCount() - 1);
}

FSCluster* FSClusterIterator::GetCurrent()
{
	return _FileSystem->GetCluster(_CurrentIndex);
}

FSClusterIterator::~FSClusterIterator()
{
}
