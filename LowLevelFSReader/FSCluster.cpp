#include "pch.h"
#include "FSCluster.h"

void FSCluster::printHexData()
{
	for (int index = 1; index < _Size + 1; index++) {
		printf("%02x ", _Data[index - 1]);

		if (index % 16 == 0) {
			cout << endl;
		}
		else if (index % 8 == 0)
		{
			cout << "  ";
		}
	}
}

FSCluster::~FSCluster()
{
}
