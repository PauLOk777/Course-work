#include <iostream>
#include <ctime>
#include <fstream>
#include <string>

using namespace std;

void selectionSort(int *Array, int size, int compare) {
	for (int i = 0; i < size; i++) {
		int index = i;
		int temp_1 = Array[i];
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
		int temp_2 = temp_1;
		Array[index] = Array[i];
		Array[i] = temp_1;
	}
}

void shellSort(int *Array, int size, int compare) {
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

void down(int *Array, int Size, int i, int compare)
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

void heapSort(int *Array, int Size, int compare)
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

void randomFillingArray(int *Array, int size) {
	srand(time(NULL));
	for (int i = 0; i < size; i++) {
		Array[i] = rand() % (size * 10) + 1;
	}
}

void showArray(int *Array, int size) {
	for (int i = 0; i < size; i++) {
		cout << Array[i] << " ";
	}
	cout << endl;
}

void manuallyFillingArray(int *Array, int size) {
	for (int i = 0; i < size; i++) {
		cin >> Array[i];
	}
}

istream& openFile(ifstream &fin, string name) {
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

void fileFillingArray(string buff, int *Array, int size) {
	string temp = "";
	int index = 0;
	for (int i = 0; i < buff.length(); i++) {
		if (buff[i] != ',') {
			temp += buff[i];
		}
		else {
			Array[index] = stoi(temp);
			index++;
			temp = "";
		}
	}
}