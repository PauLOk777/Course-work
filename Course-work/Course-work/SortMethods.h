#pragma once
#include <fstream>

using namespace std;

void selectionSort(double *, int, int);
void randomFillingArray(double *, int, double, double);
void showArray(double *, int);
void shellSort(double *, int, int);
void down(double *, int, int, int);
void heapSort(double *, int, int);
istream& openFileINPUT(ifstream &, string);
istream& readSize(ifstream &, string &, int &);
ostream& openFileOUTPUT(ofstream &, string);
void fileFillingArray(string, double *, int);
void chooseMethod(double *Array, int size);
void manuallyFillingArray(double *Array, int size);
double *chooseAction(int &);
void writeFile(double *Array, int size);