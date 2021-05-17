/*
 * nested_template_classes.cpp
 *
 *  Created on: 15 Mar 2021
 *      Author: Bowen Li
 */

#include <iostream>
#include "ring.h"

using namespace std;
using namespace advanced_cpp;

int main() {
	ring<string> text_ring(3);

	text_ring.add("one");
	text_ring.add("two");
	text_ring.add("three");

	// C++ 98 style
	for (ring<string>::iterator it = text_ring.begin(); it != text_ring.end(); it++) {
		cout << *it << endl;
	}
	
	cout << endl;
	
	// C++ 11 style
	for (string value : text_ring) {
		cout << value << endl;
	}

	return 0;
}
