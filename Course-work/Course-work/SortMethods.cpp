#include <iostream>
#include <ctime>

using namespace std;

//template <typename T>
bool compare(int a, int b) { return a < b; }

//template <typename T>
void selectionSort(int *Array, int size) {
	for (int i = 0; i < size; i++) {
		int index = i;
		int temp_1 = Array[i];
		for (int j = i; j < size; j++) {
			if (temp_1 > Array[j]) {
				temp_1 = Array[j];
				index = j;
			}
		}
		int temp_2 = temp_1;
		Array[index] = Array[i];
		Array[i] = temp_1;
	}
}

void shellSort(int *Array, int size) {
	for (int i = (size - 1) / 2; i > 0; i/=2) {
		for (int j = i; j != size; j++) {
			for (int k = j; k >= i; k -= i) {
				if (Array[k - i] > Array[k]) {
					swap(Array[k - i], Array[k]);
				}
			}
		}
	}
}

//template <typename T>
void fillingArray(int *Array, int size) {
	srand(time(NULL));
	for (int i = 0; i < size; i++) {
		Array[i] = rand() % (size * 10) + 1;
	}
}

//template <typename T>
void showArray(int *Array, int size) {
	for (int i = 0; i < size; i++) {
		cout << Array[i] << " ";
	}
	cout << endl;
}