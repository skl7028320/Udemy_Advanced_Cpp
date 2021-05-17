/*
 * standard_exceptions.cpp
 *
 *  Created on: 8 Mar 2021
 *      Author: libowen
 */

#include <iostream>

using namespace std;

class CanGoWrong {
public:
	CanGoWrong() {
		char *p_memory = new char[999999999999999];
		delete[] p_memory;
	}
};

int main() {
	try {
		CanGoWrong wrong;
	}
	catch (bad_alloc &e) {
		cout << "Caught exception: " << e.what() << endl;
	}

	cout << "Still running" << endl;

	return 0;
}
