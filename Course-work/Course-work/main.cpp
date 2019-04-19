#include <iostream>
#include "SortMethods.h"
#include <string>
#include <fstream>

using namespace std;

int main() {
	int size = 1;
	double *Array;
	
	Array = chooseAction(size);
	chooseMethod(Array, size);
	writeFile(Array, size);

	delete[] Array;
	system("pause");
	return 0;
}