/*
 * unique_pointers.cpp
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

class Temp {
private:
	unique_ptr<Test> test_ptr_;

public:
	// member smart pointers must be allocated in constructor and they will be automatically deleted before destructor
	// is called
	Temp() : test_ptr_(new Test){}
};

int main() {
	/// Example with C++ built-in type
	//auto_ptr<int> int_ptr(new int); // Similar auto pointer prior to C++11, but deprecated
	unique_ptr<int> int_ptr(new int);
	
	*int_ptr = 7;

	cout << *int_ptr << endl;

	/// Example with custom type
	//unique_ptr<Test> test_ptr = make_unique<Test>(); // C++14 feature
	unique_ptr<Test> test_ptr(new Test());

	test_ptr->greet();

	// Unique pointer can be used on array
	unique_ptr<Test[]> test_arr_ptr(new Test[2]);

	test_arr_ptr[1].greet();

	// The old way
	Test *test_ptr2 = new Test();

	test_ptr2->greet();

	delete test_ptr2; // Must explicitly deallocate memory, otherwise memory leak

	// Smart pointers are deallocated after the associated scope is finished
	{
		unique_ptr<Test> test_ptr3(new Test);

		test_ptr3->greet();
	}

	/// An example with smart pointer as member variable
	Temp temp;

	cout << "finished" << endl;

	return 0;
}
