/*
 * CatchingSubclassExceptions.cpp
 *
 *  Created on: 9 Mar 2021
 *      Author: libowen
 */

#include <iostream>
#include <exception>

using namespace std;

void goes_wrong() {
	bool error1_detected = true;
	bool error2_detected = false;

	if (error1_detected) {
		throw bad_alloc();
	}

	if (error2_detected) {
		throw exception();
	}
}

int main() {
	try {
		goes_wrong();
	}
	catch (bad_alloc &e) {
		cout << "Catching bad_alloc: " << e.what() << endl;
	}
	catch (exception &e) {
		cout << "Catching exception: " << e.what() << endl;
	}

	return 0;
}
