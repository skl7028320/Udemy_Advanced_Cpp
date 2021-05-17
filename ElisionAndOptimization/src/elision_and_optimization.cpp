/*
 * elision_and_optimization.cpp
 *
 *  Created on: 18 Mar 2021
 *      Author: Bowen Li
 */

#include <iostream>
#include <vector>

using namespace std;

class Test {
public:
	Test() {
		cout << "Constructor" << endl;
	}

	Test(int i) {
		cout << "Parameterized constructor" << endl;
	}

	Test(const Test &other) {
		cout << "Copy constructor" << endl;
	}

	Test &operator=(const Test &other) {
		cout << "Copy assignment operator" << endl;

		return *this;
	}

	~Test() {
		cout << "Destructor" << endl;
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
