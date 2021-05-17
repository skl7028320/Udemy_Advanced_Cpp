/*
 * overloading_comparison_operators.cpp
 *
 *  Created on: 14 Mar 2021
 *      Author: Bowen Li
 */

#include <iostream>
#include "Complex.h"

using namespace std;
using namespace advanced_cpp;

int main() {
	Complex c1(3, 2);
	Complex c2(1, 3);
	
	if (c1 == c2) {
		cout << "Equal" << endl;
	}
	else {
		cout << "Not equal" << endl;
	}
	
	if (c1 != c2) {
		cout << "Not equal" << endl;
	}
	else {
		cout << "Equal" << endl;
	}

	return 0;
}
