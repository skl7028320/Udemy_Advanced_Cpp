/*
 * decltype_and_typeid.cpp
 *
 *  Created on: 14 Mar 2021
 *      Author: Bowen Li
 */

#include <iostream>
#include <typeinfo>

using namespace std;

class Test {

};

int main() {
	string value;
	
	// Name mangling
	cout << typeid(value).name() << endl;
	
	decltype(value) name = "Bob";

	cout << typeid(name).name() << endl;
	cout << name << endl;

	Test test;

	// Name mangling
	cout << typeid(test).name() << endl;

	return 0;
}
