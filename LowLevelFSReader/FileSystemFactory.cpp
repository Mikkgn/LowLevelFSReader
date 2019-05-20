#include "pch.h"
#include "FileSystemFactory.h"


FileSystemFactory::FileSystemFactory()
{
}

BaseFileSystem* FileSystemFactory::GetFileSystem(FileReader* fileReader)
{
	FileSystemOEMName *fsName = (FileSystemOEMName*)fileReader->GetData(0, 1024);
	
	if (!strcmp(fsName->Name, "NTFS    ")) {
		return new NTFSFileSystem(fileReader);
	}
	if (!strcmp(fsName->Name, "MSDOS5.0")) {
		return new FATFileSystem(fileReader);
	}
	if (!strcmp(fsName->Name, "EXFAT   ")) {
		return new ExFATFileSystem(fileReader);
	}

	throw exception("Not supported file system");
}

FileSystemFactory::~FileSystemFactory()
{
}
