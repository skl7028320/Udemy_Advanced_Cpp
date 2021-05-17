/*
 * basic_exceptions.cpp
 *
 *  Created on: 8 Mar 2021
 *      Author: libowen
 */

#include <iostream>

using namespace std;

void might_go_wrong() {
	bool error1 = false;
	bool error2 = true;

	if (error1) {
		throw "Something went wrong.";
	}

	if (error2) {
		throw string("Something went wrong");
	}
}

void uses_might_go_wrong() {
	might_go_wrong();
}

int main() {
	try {
		uses_might_go_wrong();
	}
	catch(int e) {
		cout << "Error code: " << e << endl;
	}
	catch(char const * e) {
		cout << "Error message: " << e << endl;
	}
	catch(string &e) {
		cout << "String error message: " << endl;
	}

	cout << "Still running..." << endl;

	return 0;
}
