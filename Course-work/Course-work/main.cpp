#include <iostream>
#include "SortMethods.h"
#include <cmath>

using namespace std;

int main() {
	int N;
	cin >> N;
	int *Array = new int[N];
	fillingArray(Array, N);
	showArray(Array, N);
	shellSort(Array, N);
	showArray(Array, N);


	delete[] Array;
	system("pause");
	return 0;
}