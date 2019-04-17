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
	int temp, compare;
	cout << "Input which method you wanna use:" << endl << "1. Insertion." << endl;
	cout << "2. Shell sort." << endl << "3. Heap sort." << endl;
	cout << "Input number of method: "; cin >> temp;
	cout << "Enter 1 if you wanna sorted from larger to smaller, else press any number: ";
	cin >> compare;
	if (temp == 1) {
		selectionSort(Array, size, compare);
		showArray(Array, size);
	}
	if (temp == 2) {
		shellSort(Array, size, compare);
		showArray(Array, size);
	}
	if (temp == 3) {
		heapSort(Array, size, compare);
		showArray(Array, size);
	}

	delete[] Array;
	system("pause");
	return 0;
}