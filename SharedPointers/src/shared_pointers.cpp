/*
 * shared_pointers.cpp
 *
 *  Created on: 21 Mar 2021
 *      Author: Bowen Li
 */

#include <iostream>
#include <memory>

using namespace std;

class Test {
public:
	Test() {
		cout << "created" << endl;
	}

	~Test() {
		cout << "destroyed" << endl;
	}

	void greet() {
		cout << "hello" << endl;
	}
};

int main() {
	// Shared pointer is similar as unique pointer but just adds a little twist that it won't get deleted until all
	// shared pointers that point to the object have gone out of scope.
	// Shared pointer can't be used with array at least in C++11

	shared_ptr<Test> test_ptr2(nullptr);

	{
		//shared_ptr<Test> test_ptr1(new Test);
		shared_ptr<Test> test_ptr1 = make_shared<Test>(); // More efficient than new

		test_ptr2 = test_ptr1; // Test object will not be destroyed after test_ptr1 is out of scope, but will be deleted
		                       // after test_ptr2 is out of scope.
	}

	cout << "finished" << endl;

	return 0;
}
