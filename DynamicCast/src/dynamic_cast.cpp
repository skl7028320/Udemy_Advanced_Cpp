/*
 * static_cast.cpp
 *
 *  Created on: 21 Mar 2021
 *      Author: Bowen Li
 */

#include <iostream>

using namespace std;

class Parent {
public:
	virtual ~Parent() = default;

	virtual void speak() {
		cout << "Parent" << endl;
	}
};

class Brother: public Parent {

};

class Sister: public Parent {

};

int main() {
	Parent parent;
	Brother brother;

	Parent *parent_ptr_to_brother = &parent;
	Brother *brother_ptr_to_brother =
			dynamic_cast<Brother*>(parent_ptr_to_brother); // dynamic cast is doing runtime type check, if you can use
														   // dynamic cast instead of static cast, use it (RTTI must be
														   // enabled for compiler)

	if (brother_ptr_to_brother == nullptr) {
		cout << "Invalid cast" << endl;
	} else {
		cout << brother_ptr_to_brother << endl;
	}

	return 0;
}
