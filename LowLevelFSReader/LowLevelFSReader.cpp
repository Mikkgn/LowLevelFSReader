
#include "pch.h"
#include <iostream>
#include <string>

#include "FileReader.h"
#include "BaseFileSystem.h"
#include "FileSystemFactory.h"


using namespace std;


void printHelp()
{
	cout << "" << endl;
	cout << "Low level file system interface" << endl;
	cout << "USAGE: LowLevelFSReader <targetFileName>" << endl;
}


int main(int argc, char** argv)
{
	string targetFileName;
	if (argc == 2) {
		targetFileName = argv[1];
		cout << targetFileName << endl;
	}
	else {
		cout << "ERROR: Not specified file name" << endl;
		printHelp();
	}

	FileReader *fileReader = NULL;
	
	try {
		fileReader = new FileReader(targetFileName);
	}
	catch (exception exc) {
		cout << exc.what() << endl;
	}

	BaseFileSystem *fileSystem = NULL;
	
	fileSystem = FileSystemFactory::GetFileSystem(fileReader);

	fileSystem->PrintSystemInfo();

}