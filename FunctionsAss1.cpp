#include <iostream>
#include <fstream>
#include <array>
#include "Header.h"

using namespace std;

//TWO PASS METHOD: Function will count how many integers are in the file so as to set the initial max capacity of the array
size_t countNumbersInFile(const string& filename) {
	ifstream inputFile(filename);
	size_t count = 0;
	int value;

	if (!inputFile) {
		cerr << "Error opening file: " << filename << endl;
		return 0;
	}

	while (inputFile >> value) {
		count++;
	}

	inputFile.close();
	return count;

}

//TWO PASS METHOD: After counting from the initial function, this will load the data into the one dimensional array
bool readDataFromFile(const string& filename, int* arr, size_t& size) {
	ifstream inputFile(filename);
	size_t index = 0;
	int value;

	if (!inputFile) {
		cerr << "Error opening file: " << filename << endl;
		return false;
	}

	while (inputFile >> value && index < size) {
		arr[index++] = value;
	}

	if (inputFile.bad()) {
		cerr << "Error reading from file: " << filename << endl;
		inputFile.close();
		return false;

	}

	size = index;
	inputFile.close();
	return true;
}

//Function to find a value in the array and if found return the index that it was found at
int findInArray(const int* arr, size_t size, int target) {
	for (size_t i = 0; i < size; i++) {
		if (arr[i] == target) {
			return static_cast<int>(i);
		}
	}
	return -1;
}

//Function to update the value at an index then return the old value and the updated value to the user
void updateValueAtIndex(int* arr, size_t size, size_t index, int newValue) {
	if (index < size) {
		int oldValue = arr[index];
		arr[index] = newValue;
		cout << "Old value at index " << index << ": " << oldValue << endl;
		cout << "New value at index " << index << ": " << newValue << endl;
	}
	else {
		cerr << "Index " << index << " is out of bounds." << endl;
	}
}

//Function to add a new integer to the end of the array
int* addValueToEnd(int* arr, size_t& size, int newValue) {
	//need to allocate a new array with an increased memory
	int* newArr = new int[size + 1];

	for (size_t i = 0; i < size; i++) {
		newArr[i] = arr[i];
	}
	newArr[size] = newValue;

	size++;

	delete[] arr;

	return newArr;
}


