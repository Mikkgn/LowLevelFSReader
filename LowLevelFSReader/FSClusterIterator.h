#pragma once
#include <iostream>
#include <windows.h>

#include "BaseIterator.h"
#include "FSCluster.h"
#include "BaseFileSystem.h"

class FSClusterIterator : public BaseIterator<FSCluster>
{
protected:
	BaseFileSystem * _FileSystem;
	long _CurrentIndex;
public:
	virtual bool IsDone();
	virtual void First();
	virtual void Next();
	virtual FSCluster* GetCurrent();
	long GetCurrentIndex() {
		return _CurrentIndex;
	}

	FSClusterIterator(BaseFileSystem* fileSystem);
	~FSClusterIterator();
};

