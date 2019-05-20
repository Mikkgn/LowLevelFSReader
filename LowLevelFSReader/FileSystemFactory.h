#pragma once
#include "BaseFileSystem.h"
#include "NTFSFileSystem.h"
#include "FATFileSystem.h"
#include "ExFATFileSystem.h"

class FileSystemFactory
{
public:
	static BaseFileSystem* GetFileSystem(FileReader* fileReader);
private:
	FileSystemFactory();
	~FileSystemFactory();
};

