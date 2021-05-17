/*
 * object_initialization.cpp
 *
 *  Created on: 15 Mar 2021
 *      Author: Bowen Li
 */

#include <iostream>

using namespace std;

class Test {
	int id { 3 }; // int id = 3; C++98 way
	string name { "Mike" }; // string name = "Mike"; C++98 way

public:
	Test() = default; // Adding the implicitly deleted default constructor
	Test(const Test &other) = default; // Explicitly declare default copy constructor, does no new stuff
	Test& operator=(const Test &other) = default; // Explicitly declare default copy assignment operator
												  // , does no new stuff

	// Copy constructor and copy assignment can be deleted explicitly
	//Test(const Test &other) = delete;
	//Test& operator=(const Test &other) = delete;

	Test(int id) :
			id(id) {
	}

	void print() {
		cout << id << ": " << name << endl;
	}
};

int main() {
	Test test;
	test.print();

	Test test1(77);
	test1.print();

	Test test2 = test1; // Copy initialization (invoking copy constructor)
	test2 = test; // Object assignment (invoking copy assignment operator)

	return 0;
}
