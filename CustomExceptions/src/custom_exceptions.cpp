/*
 * standard_exceptions.cpp
 *
 *  Created on: 8 Mar 2021
 *      Author: libowen
 */

#include <iostream>
#include <exception>

using namespace std;

class MyException : public exception {
public:
	virtual const char* what() const throw() {
		return "Something bad happened!";
	}
};

class Test {
public:
	void goes_wrong() {
		throw MyException();
	}
};

int main() {
	Test test;

	try {
		test.goes_wrong();
	}
	catch (MyException &e) {
		cout << e.what() << endl;
	}

	return 0;
}
