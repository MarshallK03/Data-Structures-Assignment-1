#pragma once
#include <iostream>
#include <fstream>

using namespace std;

//TWO PASS METHOD: Function will count how many integers are in the file so as to set the initial max capacity of the array
size_t countNumbersInFile(const string& filename);

//TWO PASS METHOD: After counting from the initial function, this will load the data into the one dimensional array
bool readDataFromFile(const string& filename, int* arr, size_t& size);

//Function to find a value in the array and if found return the index that it was found at
int findInArray(const int* arr, size_t size, int target);

//Function to update the value at an index then return the old value and the updated value to the user
void updateValueAtIndex(int* arr, size_t size, size_t index, int newValue);

//Function to add a new integer to the end of the array
int* addValueToEnd(int* arr, size_t& size, int newValue);

//Function to replace a value at an index with zero
void replaceValueWithZero(int* arr, size_t size, size_t index) {
	if (index < size) {
		int oldValue = arr[index];
		arr[index] = 0;
		cout << "Old value at " << index << ": " << oldValue << endl;
		cout << "New value at " << index << ": " << arr[index] << endl;
	}
	else {
		cerr << "Index " << index << " is out of bounds." << endl;
	}
}