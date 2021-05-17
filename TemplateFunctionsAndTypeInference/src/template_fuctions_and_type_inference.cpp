/*
 * template_functions.cpp
 *
 *  Created on: 14 Mar 2021
 *      Author: Bowen Li
 */

#include <iostream>

using namespace std;

template<typename T>
void print(T obj) {
	cout << "Template version: " << obj << endl;
}

void print(int value) {
	cout << "Non-template version: " << value << endl;
}

template<typename T>
void show() {
	cout << T() << endl;
}

int main() {
	print<string>("Hello");
	print<int>(5);
	
	print("Test");

	print(7);
	print<>(6);

	// The type should be specified when calling the function
	show<double>();

	return 0;
}
