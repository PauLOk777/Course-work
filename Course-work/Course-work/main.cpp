#include <iostream>
#include "SortMethods.h"
#include <string>

using namespace std;

int main() {
	int size;
	cout << "Input size of array: "; cin >> size;
	int *Array = new int[size];
	fillingArray(Array, size);
	showArray(Array, size);
	int temp;
	cout << "Input which method you wanna use:" << endl << "1. Insertion." << endl;
	cout << "2. Shell sort." << endl << "3. Heap sort." << endl;
	cout << "Input number of method: "; cin >> temp;
	if (temp == 1) {
		selectionSort(Array, size);
		showArray(Array, size);
	}
	if (temp == 2) {
		shellSort(Array, size);
		fillingArray(Array, size);
		showArray(Array, size);
	}
	if (temp == 3) {
		heapSort(Array, size);
		fillingArray(Array, size);
		showArray(Array, size);
	}

	delete[] Array;
	system("pause");
	return 0;
}