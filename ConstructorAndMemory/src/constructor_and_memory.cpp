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
	// Simplified by copy elision and return value optimization
	Test test1 = get_test();
	
	cout << test1 << endl;

	// Not optimal because overhead copy constructor is called
	vector<Test> vec;
	vec.push_back(Test());

	return 0;
}
