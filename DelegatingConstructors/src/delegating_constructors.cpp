/*
 * delegating_constructors.cpp
 *
 *  Created on: 18 Mar 2021
 *      Author: Bowen Li
 */

#include <iostream>

using namespace std;

class Parent {
	int dogs;
	string text;

public:
	// Calling constructor within another constructor, delegating constructors
	Parent() : Parent("hello") {
		dogs = 5;
		cout << "No parameter parent constructor." << endl;
	}

	Parent(string text) {
		dogs = 5;
		this->text = text;
		cout << "String parent constructor." << endl;
	}
};

class Child : public Parent {
public:
	Child() = default;
};

int main() {
	Parent parent("hello");
	Child child;
	
	return 0;
}
