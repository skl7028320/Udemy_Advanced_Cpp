/*
 * move_assignment_operator.cpp
 *
 *  Created on: 19 Mar 2021
 *      Author: Bowen Li
 */

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Test {
private:
	static const int SIZE = 100;
	int *ptr_buffer_{nullptr};

public:
	Test() {
		ptr_buffer_ = new int[SIZE]{};
		//memset(ptr_buffer_, 0, sizeof(int)*SIZE);

	}

	Test(int i) {
		ptr_buffer_ = new int[SIZE]{};

		for (int i = 0; i < SIZE; i++) {
			ptr_buffer_[i] = 7 * i;
		}
	}

	Test(const Test &other) {
		ptr_buffer_ = new int[SIZE]{};

		memcpy(ptr_buffer_, other.ptr_buffer_, sizeof(int) * SIZE);
	}

	// Move constructor which takes an rvalue and steal memory from it
	Test(Test &&other) {
		cout << "Move constructor" << endl;
		ptr_buffer_ = other.ptr_buffer_;
		other.ptr_buffer_ = nullptr; // To avoid the original temporary rvalue deallocating the stolen memory
	}

	// Move assignment operator which takes an rvalue and steal memory from it
	Test &operator=(Test &&other) {
		cout << "Move assignment operator" << endl;

		delete [] ptr_buffer_; // Delete the memory that is held by the current object
		ptr_buffer_ = other.ptr_buffer_;
		other.ptr_buffer_ = nullptr; // To avoid the original temporary rvalue deallocating the stolen memory

		return *this;
	}

	Test &operator=(const Test &other) {
		ptr_buffer_ = new int[SIZE]{};

		memcpy(ptr_buffer_, other.ptr_buffer_, sizeof(int) * SIZE);

		return *this;
	}

	~Test() {
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
	vector<Test> vec;
	vec.push_back(Test()); // Move constructor called

	Test test;
	test = get_test(); // Move assignment operator called

	return 0;
}
