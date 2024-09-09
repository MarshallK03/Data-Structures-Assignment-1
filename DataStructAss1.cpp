#include <iostream>
#include <fstream>
#include <stdexcept>
#include "FunctionsAss1.cpp"

using namespace std;

int main() {
	const string filename = "A1input.txt";
	cout << "Loading data into array" << endl << endl;
	size_t size = countNumbersInFile(filename);
	if (size == 0) {
		cerr << "No data found or file could not be read." << endl;
		return 1;
	}

	int* data = new int[size];
	readDataFromFile(filename, data, size);

	cout << "Array created from data: " << endl;
	for (size_t i = 0; i < size; i++) {
		cout << data[i] << endl << endl;
	}

	int target = 5;
	cout << "Testing find in array function with integer 5" << endl;
	int index = findInArray(data, size, target);

	if (index != -1) {
		cout << "The integer " << target << " was found at the index " << index << "." << endl;
	}
	else {
		cout << "The integer " << target << " was not found in the array" << endl;
	}

	size_t updateIndex = 2;
	int newValue = 42;
	cout << "Testing update value at index function" << endl;
	updateValueAtIndex(data, size, updateIndex, newValue);

	int newInt = 87;
	cout << endl << "Testing add value to end of array function" << endl;
	data = addValueToEnd(data, size, newInt);

	size_t replaceIndex = 3;
	cout << endl << "Testing replace value with zero function" << endl;
	replaceValueWithZero(data, size, replaceIndex);

	cout << "Updated data in the array: " << endl;

	for (size_t i = 0; i < size; i++) {
		cout << data[i] << endl;
	}

	delete[] data;
	return 0;
}