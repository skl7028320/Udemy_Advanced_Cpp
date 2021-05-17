/*
 * overloading_the_dereference_operator.cpp
 *
 *  Created on: 14 Mar 2021
 *      Author: Bowen Li
 */

#include <iostream>
#include "Complex.h"

using namespace std;
using namespace advanced_cpp;

int main() {
	Complex c1(2, 4);
	
	cout << *c1 << endl;
	
	return 0;
}
