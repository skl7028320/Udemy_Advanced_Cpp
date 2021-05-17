/*
 * abstract_functions_and_pure_virtual_functions.cpp
 *
 *  Created on: 14 Mar 2021
 *      Author: Bowen Li
 */

#include <iostream>

using namespace std;

// Abstract class: class that has pure virtual function(s)
class Animal {
public:
	virtual void speak() = 0; // Pure virtual function
	virtual void run() = 0;

	virtual ~Animal() = default;
};

class Dog : public Animal {
public:
	virtual void speak() {
		cout << "Woof!" << endl;
	}
};

class Labrador : public Dog {
public:
	Labrador() {
		cout << "New labrador!" << endl;
	}

	virtual void run() {
		cout << "Labrador running!" << endl;
	}
};

void test(Animal &a) {
	a.run();
}

int main() {
	// Failure, Animal is an abstract class
	//Animal animal;

	// Failure, Dog is an abstract class
	//Dog dog;

	Labrador lab;
	lab.run();
	lab.speak();
	
	Labrador lbs[5];

	Animal *animals[5];
	animals[0] = &lab;

	animals[0]->speak();

	test(lab);

	return 0;
}
