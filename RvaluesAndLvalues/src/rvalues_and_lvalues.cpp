/*
 * elision_and_optimization.cpp
 *
 *  Created on: 18 Mar 2021
 *      Author: Bowen Li
 */

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Test {
private:
	static const int SIZE = 100;
	int *ptr_buffer_;

public:
	Test() {
		cout << "Constructor" << endl;

		ptr_buffer_ = new int[SIZE]{};
		//memset(ptr_buffer_, 0, sizeof(int)*SIZE);

	}

	Test(int i) {
		cout << "Parameterized constructor" << endl;

		ptr_buffer_ = new int[SIZE]{};

		for (int i = 0; i < SIZE; i++) {
			ptr_buffer_[i] = 7 * i;
		}
	}

	Test(const Test &other) {
		cout << "Copy constructor" << endl;

		ptr_buffer_ = new int[SIZE]{};

		memcpy(ptr_buffer_, other.ptr_buffer_, sizeof(int) * SIZE);
	}

	Test &operator=(const Test &other) {
		cout << "Copy assignment operator" << endl;

		ptr_buffer_ = new int[SIZE]{};

		memcpy(ptr_buffer_, other.ptr_buffer_, sizeof(int) * SIZE);

		return *this;
	}

	~Test() {
		cout << "Destructor" << endl;

		delete [] ptr_buffer_;
	}

	friend ostream &operator<<(ostream &out, const Test &test);
};

ostream &operator<<(ostream &out, const Test &test) {
	out << "Hello from test";

	return out;
}

Test get_test() {
	return Test();
}

int main() {
	int value1 = 7;

	// Lvalue is anything you can take address of, Rvalue is the opposite
	int *value1_ptr = &value1;
	//int *literal_int_ptr = &7;

	// Values returned from functions (temporary values) are Rvalue
	Test test = get_test();
	Test *test_ptr = &test;
	//Test *test_ptr = &get_test();

	int *value2_ptr = &++value1; // Prefix increment returns Lvalue
	//int *value3_ptr = &value1++; // postfix increment returns Rvalue

	// value1 is Lvalue but the whole expression is Rvalue
	//int s = &(7 + value1);

	return 0;
}
