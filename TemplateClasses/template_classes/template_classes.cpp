/*
 * template_classes.cpp
 *
 *  Created on: 14 Mar 2021
 *      Author: Bowen Li
 */

#include <iostream>

using namespace std;

template<class T, class K>
class Test {
private:
	T obj;

public:
	Test(T obj) {
		this->obj = obj;
	}

	void print() {
		cout << obj;
	}
};

int main() {
	Test<string, int> test1("Hello");
	test1.print();
	
	
	return 0;
}
