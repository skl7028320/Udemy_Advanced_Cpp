/*
 * vectors_and_memory.cpp
 *
 *  Created on: 11 Mar 2021
 *      Author: libowen
 */

#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<double> numbers(0);
	cout << "Size: " << numbers.size() << endl;
	
	int capacity = numbers.capacity();
	cout << "Capacity: " << capacity << endl;

	for (int i = 0; i < 10000; i++) {
		if (numbers.capacity() != capacity) {
			capacity = numbers.capacity();
			cout << "Capacity: " << capacity << endl;
		}

		numbers.push_back(i);
	}

	numbers.reserve(100000);
	cout << "Size: " << numbers.size() << endl;
	cout << "Capacity: " << numbers.capacity() << endl;

	return 0;
}

