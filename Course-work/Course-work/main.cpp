#include <iostream>
#include "SortMethods.h"
#include <string>
#include <fstream>

using namespace std;

int main() {
	int size = 1, num;
	int *Array = new int[size];
	cout << "Enter the number what do you want to do:" << endl;
	cout << "1. Read from file." << endl << "1. Random fill array." << endl;
	cout << "3. Manually fill array." << endl; cin >> num;
	while (true) {
		if (num == 1) {
			ifstream fin;
			string name, buff;
			cout << "Input name of the file: ";
			cin >> name;
			openFile(fin, name);
			readSize(fin, buff, size);
			fileFillingArray(buff, Array, size);
			showArray(Array, size);
			break;
		}
		cout << "Enter 1, 2 or 3, please." << endl;
		cin >> num;
	}
	cout << "Input size of array: "; cin >> size;
	int temp, compare;
	cout << "Input which method you wanna use:" << endl << "1. Insertion." << endl;
	cout << "2. Shell sort." << endl << "3. Heap sort." << endl;
	cout << "Input number of method: "; cin >> temp;
	cout << "Enter 1 if you wanna sorted from smaller to larger, else press any number: ";
	cin >> compare;
	while (true) {
		if (temp == 1) {
			selectionSort(Array, size, compare);
			showArray(Array, size);
			break;
		}
		if (temp == 2) {
			shellSort(Array, size, compare);
			showArray(Array, size);
			break;
		}
		if (temp == 3) {
			heapSort(Array, size, compare);
			showArray(Array, size);
			break;
		}
		cout << "Input 1 or 2 or 3 please." << endl;
		cin >> temp;
	}
	
	delete[] Array;
	system("pause");
	return 0;
}