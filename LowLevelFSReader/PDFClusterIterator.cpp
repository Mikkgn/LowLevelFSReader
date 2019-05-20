#include "pch.h"
#include "PDFClusterIterator.h"


PDFClusterIterator::PDFClusterIterator(BaseFileSystem* fileSystem): BaseIterator()
{
	_ClusterIterator = new FSClusterIterator(fileSystem);
}


void PDFClusterIterator::First() 
{
	_ClusterIterator->First();
	while (!_ClusterIterator->IsDone())
	{
		FSCluster* cluster = _ClusterIterator->GetCurrent();
		if (isClusterHasPDFHeader(cluster)) 
		{
			break;
		}
		_ClusterIterator->Next();
	}
}

void PDFClusterIterator::Next()
{
	while (!_ClusterIterator->IsDone())
	{
		FSCluster* cluster = _ClusterIterator->GetCurrent();
		if (isClusterHasPDFHeader(cluster))
		{
			break;
		}
		_ClusterIterator->Next();
	}
}

bool PDFClusterIterator::IsDone()
{
	return _ClusterIterator->IsDone();
}

FSCluster* PDFClusterIterator::GetCurrent()
{
	return _ClusterIterator->GetCurrent();
}

bool PDFClusterIterator::isClusterHasPDFHeader(FSCluster* cluster) {

	BYTE pdfSignature[] = { 0x25, 0x50, 0x44, 0x46 };
	BYTE* clusterData = cluster->GetData();
	const string needle(pdfSignature, pdfSignature + 4);
	const string haystack(clusterData, clusterData + sizeof(clusterData));
	size_t index = haystack.find(needle);
	if (index == string::npos)
	{
		return false;
	}
	else
	{
		return true;
	}
}


PDFClusterIterator::~PDFClusterIterator()
{
}
