#include <iostream>
#include "SortMethods.h"
#include <string>
#include <fstream>

using namespace std;

int main() {
	int size = 1, *Array;
	
	Array = chooseAction(size);
	chooseMethod(Array, size);
	
	delete[] Array;
	system("pause");
	return 0;
}