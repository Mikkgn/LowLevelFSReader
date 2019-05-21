
#include "pch.h"
#include <iostream>
#include <string>

#include "FileReader.h"
#include "BaseFileSystem.h"
#include "FileSystemFactory.h"
#include "FSClusterIterator.h"
#include "PDFClusterIterator.h"


using namespace std;


void printHelp()
{
	cout << "" << endl;
	cout << "Low level file system interface" << endl;
	cout << "Return cluster numbers, which contain PDF header" << endl;
	cout << "USAGE: LowLevelFSReader [--show-hex-data] <targetFileName>" << endl;
	cout << "" << endl;
	cout << "--show-hex-data     show founded clusters hex data" << endl;
}


int main(int argc, char** argv)
{
	string targetFileName;
	bool showHexData;
	if (argc == 2) {
		targetFileName = argv[1];
		showHexData = false;
	}
	else if (argc == 3) {
		showHexData = bool(!strcmp(argv[1], "--show-hex-data"));
		targetFileName = argv[2];
	}
	else {
		cout << "ERROR: Not specified file name" << endl;
		printHelp();
		return 1;
	}

	cout << "Processed file " + targetFileName << endl;
	FileReader *fileReader = NULL;

	try {
		fileReader = new FileReader(targetFileName);
	}
	catch (exception exc) {
		cout << exc.what() << endl;
		printHelp();
		return 1;
	}

	BaseFileSystem *fileSystem = NULL;
	try {
		fileSystem = FileSystemFactory::GetFileSystem(fileReader);
	}
	catch (exception exc) {
		cout << exc.what() << endl;
		printHelp();
		return 1;
	}

	fileSystem->PrintSystemInfo();

	PDFClusterIterator *pdfClusterIterator = new PDFClusterIterator(fileSystem);
	try {
		pdfClusterIterator->First();
	}
	catch (exception exc) {
		cout << exc.what() << endl;
		return 1;
	}
	while (!pdfClusterIterator->IsDone()) {
		FSCluster *cluster = pdfClusterIterator->GetCurrent();
		cout << "Founded PDF header in cluster number " + to_string(pdfClusterIterator->GetCurrentIndex()) << endl;
		if (showHexData)
		{
			cout << "Hex data: " << endl;
			cout << "" << endl;
			cluster->printHexData();
		}
		pdfClusterIterator->Next();
	}

	delete pdfClusterIterator;
	delete fileSystem;
	delete fileReader;
	return 0;

}