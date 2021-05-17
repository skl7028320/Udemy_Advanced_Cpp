/*
 * overloading_plus.cpp
 *
 *  Created on: 14 Mar 2021
 *      Author: Bowen Li
 */

#include <iostream>
#include "Complex.h"

using namespace std;
using namespace advanced_cpp;

int main() {
	Complex c1(3, 4);
	Complex c2(2, 3);
	cout << c1 + c2 << endl;

	Complex c3 = c1 + c2;
	cout << c1 + c2 + c3 << endl;

	Complex c4(4, 2);
	Complex c5 = c4 + 7;
	cout << c5 << endl;

	Complex c6(1, 7);
	cout << 3.2 + c6 << endl;

	cout << 7 + c1 + c4 + 4.5 + c5 << endl;

	return 0;
}
