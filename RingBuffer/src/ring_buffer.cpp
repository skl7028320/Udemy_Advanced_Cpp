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
	text_ring.add("four");
	
	for (int i = 0; i < text_ring.size(); i++) {
		cout << text_ring.get(i) << endl;
	}
	
	cout << endl;

	ring<int>::iterator it;
	it.print();

	return 0;
}
