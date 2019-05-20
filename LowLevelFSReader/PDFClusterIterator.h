#pragma once
#include <iostream>
#include <windows.h>

#include "BaseFileSystem.h"
#include "FSClusterIterator.h"

using namespace std;

class PDFClusterIterator: public BaseIterator<FSCluster>
{
private:
	FSClusterIterator * _ClusterIterator;
	bool isClusterHasPDFHeader(FSCluster* cluster);
public:
	virtual void Next();
	virtual void First();
	virtual bool IsDone();
	virtual FSCluster* GetCurrent();

	PDFClusterIterator(BaseFileSystem* fileSystem);
	~PDFClusterIterator();
};

