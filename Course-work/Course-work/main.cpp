#include <iostream>
#include "SortMethods.h"
#include <string>
#include <fstream>

using namespace std;

int main() {
	int size = 1;
	int *Array = new int[size];
	
	int num;
	cout << "Enter the number what do you want to do:" << endl;
	cout << "1. Read from file." << endl << "2. Random fill array." << endl;
	cout << "3. Manually fill array." << endl; cin >> num;
	while (true) {
		if (num == 1) {
			ifstream fin;
			string name, buff;
			cout << "Input name of the file: ";
			cin >> name;
			openFile(fin, name);
			readSize(fin, buff, size);
			delete[] Array;
			Array = new int[size];
			fileFillingArray(buff, Array, size);
			showArray(Array, size);
			fin.close();
			break;
		}
		if (num == 2) {
			int begin, end;
			cout << "Input size of array: "; cin >> size;
			delete[] Array;
			Array = new int[size];
			cout << "Input range(2 numbers): "; cin >> begin >> end;
			randomFillingArray(Array, size, begin, end);
			showArray(Array, size);
			break;
		}
		if (num == 3) {
			cout << "Input size of array: "; cin >> size;
			delete[] Array;
			Array = new int[size];
			manuallyFillingArray(Array, size);
			showArray(Array, size);
			break;
		}
		cout << "Enter 1, 2 or 3, please." << endl;
		cin >> num;
	}
	chooseMethod(Array, size);
	
	delete[] Array;
	system("pause");
	return 0;
}