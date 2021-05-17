/*
 * lambda_capture_expressions.cpp
 *
 *  Created on: 17 Mar 2021
 *      Author: Bowen Li
 */

#include <iostream>

using namespace std;

int main() {
	int one = 1, two = 2, three = 3;
	
	// Capture one and two by value
	[one, two](){cout << one << ", " << two << endl;}();
	
	// Capture all local variables by value
	[=](){cout << one << ", " << two << endl;}();

	// Capture all local variables by value but catch three by reference
	[=, &three](){ three = 7; cout << three << endl; }();

	// Capture all local variables by reference
	[&](){ two = 100; cout << three << endl; }();

	// Capture all local variables by reference, but two and three by value
	[&, two, three](){ one = 100; cout << one << ", " << two << ", " << three << endl; }();

	return 0;
}
