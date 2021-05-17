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
	void speak() {
		cout << "Parent" << endl;
	}
};

class Brother : public Parent {

};

class Sister : public Parent {

};

int main() {
	float value = 3.23;
	
	// C style casting
	cout << (int)value << endl;
	cout << int(value) << endl;

	// Static cast
	cout << static_cast<int>(value) << endl;
	
	Parent parent;
	Brother brother;

	//Brother *brother_ptr_to_parent = &parent; // Error
	Brother *brother_ptr_to_parent = static_cast<Brother *>(&parent);
	cout << brother_ptr_to_parent << endl;

	Parent *parent_ptr_to_brother = &brother; // Polymorphism
	Brother *brother_ptr_to_brother = &brother; // Straightforward usage of ptr
	brother_ptr_to_brother = static_cast<Brother *>(parent_ptr_to_brother); // Error-prone because static cast only do
																			// compiler check but not runtime check
	cout << brother_ptr_to_brother << endl;

	//Parent &&parent_rvalue_ref = parent; // Error
	Parent &&parent_rvalue_ref = static_cast<Parent &&>(parent);
	parent_rvalue_ref.speak();

	return 0;
}
