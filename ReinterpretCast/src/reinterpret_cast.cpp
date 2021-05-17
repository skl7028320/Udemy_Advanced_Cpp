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
	Sister sister;

	Parent *parent_ptr_to_brother = &brother;
	//Sister *sister_ptr_to_sister = static_cast<Sister *>(parent_ptr_to_brother); // Works, but super unsafe and pointless
	//Sister *sister_ptr_to_sister = dynamic_cast<Sister*>(parent_ptr_to_brother); // Returns nullptr
	Sister *sister_ptr_to_sister =
			reinterpret_cast<Sister*>(parent_ptr_to_brother); // Reinterpret cast is doing binary cast meaning all most every
															  // type can be casted, normally not needed unless dealing with
															  // bad written APIs

	if (sister_ptr_to_sister == nullptr) {
		cout << "Invalid cast" << endl;
	} else {
		cout << sister_ptr_to_sister << endl;
	}

	return 0;
}
