/*
 * main.cpp
 *
 *  Created on: 13 Mar 2021
 *      Author: Bowen Li
 */

#include "Complex.h"
#include <iostream>

using namespace std;
using namespace advanced_cpp;

int main() {
	Complex complex1(1.0, 1.0);
	cout << complex1 << endl;

	// Copy initialization, running copy constructor
	Complex complex2 = complex1;
	cout << complex2 << endl;

	// Running copy assignment operator
	Complex complex3;
	complex3 = complex2;
	cout << complex3 << endl;

	// Chain output stream
	cout << complex3 << " " << complex2 << endl;

	return 0;
}
