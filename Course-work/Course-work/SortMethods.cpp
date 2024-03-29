#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

void selectionSort(double *Array, int size, int compare) {
	for (int i = 0; i < size; i++) {
		int index = i;
		double temp_1 = Array[i];
		if (compare == 1) {
			for (int j = i; j < size; j++) {
				if (temp_1 > Array[j]) {
					temp_1 = Array[j];
					index = j;
				}
			}
		}
		else {
			for (int j = i; j < size; j++) {
				if (temp_1 < Array[j]) {
					temp_1 = Array[j];
					index = j;
				}
			}
		}
		double temp_2 = temp_1;
		Array[index] = Array[i];
		Array[i] = temp_1;
	}
}

void shellSort(double *Array, int size, int compare) {
	for (int i = (size - 1) / 2; i > 0; i/=2) {
		for (int j = i; j != size; j++) {
			if (compare == 1) {
				for (int k = j; k >= i; k -= i) {
					if (Array[k - i] > Array[k]) {
						swap(Array[k - i], Array[k]);
					}
				}
			}
			else {
				for (int k = j; k >= i; k -= i) {
					if (Array[k - i] < Array[k]) {
						swap(Array[k - i], Array[k]);
					}
				}
			}
		}
	}
}

void down(double *Array, int Size, int i, int compare)
{	
	while (2 * i + 1 < Size)
	{
		if (compare != 1) {
			if (2 * i + 2 >= Size)
			{
				if (Array[i] >= Array[2 * i + 1])
				{
					swap(Array[i], Array[2 * i + 1]);
					i = 2 * i + 1;
					break;
				}
			}
			else
			{
				if (Array[2 * i + 1] < Array[2 * i + 2] && Array[i] > Array[2 * i + 1])
				{
					swap(Array[i], Array[2 * i + 1]);
					i = 2 * i + 1;
					continue;
				}
				if (Array[2 * i + 1] >= Array[2 * i + 2] && Array[i] > Array[2 * i + 2])
				{
					swap(Array[i], Array[2 * i + 2]);
					i = 2 * i + 2;
					continue;
				}
			}
			break;
		}
		else {
			if (2 * i + 2 >= Size)
			{
				if (Array[i] <= Array[2 * i + 1])
				{
					swap(Array[i], Array[2 * i + 1]);
					i = 2 * i + 1;
					break;
				}
			}
			else
			{
				if (Array[2 * i + 1] > Array[2 * i + 2] && Array[i] < Array[2 * i + 1])
				{
					swap(Array[i], Array[2 * i + 1]);
					i = 2 * i + 1;
					continue;
				}
				if (Array[2 * i + 1] <= Array[2 * i + 2] && Array[i] < Array[2 * i + 2])
				{
					swap(Array[i], Array[2 * i + 2]);
					i = 2 * i + 2;
					continue;
				}
			}
			break;
		}
	}
}

void heapSort(double *Array, int Size, int compare)
{
	int k = Size / 2 - 1, i = Size;
	while (k != -1)
	{
		down(Array, Size, k, compare);
		k--;
	}
	Size--;
	while (Size != 0)
	{
		swap(Array[0], Array[Size]);
		down(Array, Size, 0, compare);
		Size--;
	}
}

void randomFillingArray(double *Array, int size, double begin, double end) {
	srand(time(NULL));
	int number;
	cout << "You want to fill array with integers or valid numbers?" << endl;
	cout << "If with integers press 1, with valid press any number."; cin >> number;
	int newBegin = begin * 10;
	int newEnd = end * 10;
	if (number != 1) {
		for (int i = 0; i < size; i++) {
			double newRandom = rand() % (newEnd - newBegin) + newBegin;
			Array[i] = newRandom / 10;
		}
	}
	else {
		for (int i = 0; i < size; i++) {
			Array[i] = rand() % (newEnd - newBegin + 1) + newBegin;
		}
	}
}

void showArray(double *Array, int size) {
	for (int i = 0; i < size; i++) {
		cout << Array[i] << " ";
	}
	cout << endl;
}

void manuallyFillingArray(double *Array, int size) {
	cout << "Input your elements: " << endl;
	for (int i = 0; i < size; i++) {
		cin >> Array[i];
	}
}

istream& openFileINPUT(ifstream &fin, string name) {
	fin.open(name);
	if (!fin.is_open()) {
		cout << "Error, we dont find this file.";
		system("pause");
		exit(1);
	}
	cout << "Input file is opened." << endl;
	return fin;
}

istream& readSize(ifstream &fin, string &buff, int &size) {
	int counter = 0;
	buff = "";
	getline(fin, buff);
	for (int i = 0; i < buff.length(); i++) {
		if (buff[i] == ',') {
			counter++;
		}
	}
	size = counter + 1;
	return fin;
}

ostream& openFileOUTPUT(ofstream &fout, string name) {
	fout.open(name);
	if (!fout.is_open()) {
		cout << "Error." << endl;
		system("pause");
		exit(1);
	}
	cout << "File was opened (created)." << endl;
	return fout;
}

void fileFillingArray(string buff, double *Array, int size) {
	string temp = "";
	int index = 0;
	for (int i = 0; i < buff.length(); i++) {
		if (buff[i] != ',') {
			temp += buff[i];
		}
		else {
			Array[index] = stod(temp);
			index++;
			temp = "";
		}
	}
	Array[index] = stod(temp);
}

void chooseMethod(double *Array, int size) {
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
}

double *chooseAction(int &size) {
	int num;
	double *Array = new double[size];
	cout << "Enter the number what do you want to do:" << endl;
	cout << "1. Read from file." << endl << "2. Random fill array." << endl;
	cout << "3. Manually fill array." << endl; cin >> num;
	while (true) {
		if (num == 1) {
			ifstream fin;
			string name, buff;
			cout << "Input name of the file: ";
			cin >> name;
			openFileINPUT(fin, name);
			readSize(fin, buff, size);
			delete[] Array;
			Array = new double[size];
			fileFillingArray(buff, Array, size);
			showArray(Array, size);
			fin.close();
			return Array;
		}
		if (num == 2) {
			double begin, end;
			while (true) {
				cout << "Input size of array (positive number): "; cin >> size;
				if (size > 0) {
					break;
				}
			}
			delete[] Array;
			Array = new double[size];
			cout << "Input range(2 numbers): "; cin >> begin >> end;
			randomFillingArray(Array, size, begin, end);
			showArray(Array, size);
			return Array;
		}
		if (num == 3) {
			while (true) {
				cout << "Input size of array (positive number): "; cin >> size;
				if (size > 0) {
					break;
				}
			}
			delete[] Array;
			Array = new double[size];
			manuallyFillingArray(Array, size);
			showArray(Array, size);
			return Array;
		}
		cout << "Enter 1, 2 or 3, please." << endl;
		cin >> num;
	}
}

void writeFile(double *Array, int size) {
	int temp;
	cout << "Do you wanna write array to file? If yes press 1, no - any number: ";
	cin >> temp;
	if (temp == 1) {
		ofstream fout;
		string name, buff = "";
		cout << "Input file name: "; cin >> name;
		openFileOUTPUT(fout, name);
		for (int i = 0; i < size - 1; i++) {
			buff += to_string(Array[i]) + ',';
		}
		buff += to_string(Array[size - 1]);
		fout << buff;
		fout.close();
	}
}