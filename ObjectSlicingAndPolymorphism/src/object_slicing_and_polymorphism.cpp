/*
 * object_slicing_and_polymorphism.cpp
 *
 *  Created on: 14 Mar 2021
 *      Author: Bowen Li
 */

#include <iostream>

using namespace std;

class Parent {
private:
	int one;

public:
	Parent() : one(0) {};

	Parent(const Parent &other) : one(0) {
		cout << "Copy parent!" << endl;
	}

	virtual void print() {
		cout << "parent" << endl;
	}

	virtual ~Parent() {}
};

class Child : public Parent {
private:
	int two;

public:
	Child() : two(0) {}

	void print() {
		cout << "child" << endl;
	}
};

int main() {
	Child c1;

	Parent *ptr_p1 = &c1;
	Parent &ref_p1 = c1;

	ptr_p1->print();
	ref_p1.print();

	// Object slicing, derived class casted to parent class
	Parent p2 = Child();
	
	p2.print();
	
	return 0;
}
