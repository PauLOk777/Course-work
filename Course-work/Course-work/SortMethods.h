#pragma once
#include <fstream>

using namespace std;

void selectionSort(int *, int, int);
void randomFillingArray(int *, int);
void showArray(int *, int);
void shellSort(int *, int, int);
void down(int *, int, int, int);
void heapSort(int *, int, int);
istream& openFile(ifstream &, string);
istream& readSize(ifstream &, string &, int &);
void fileFillingArray(string, int *, int);