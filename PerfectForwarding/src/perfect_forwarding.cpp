/*
 * perfect_forwarding.cpp
 *
 *  Created on: 21 Mar 2021
 *      Author: Bowen Li
 */

#include <iostream>

using namespace std;

class Test {

};

template<typename T>
void call(T &&arg) {
	//check(static_cast<T>(arg));
	check(forward<T>(arg));
}

void check(Test &test) {
	cout << "Lvalue reference" << endl;
}

void check(Test &&test) {
	cout << "Rvalue reference" << endl;
}

int main() {
	auto &&test_rvalue_ref = Test();

	Test test;
	auto &&test_lvalue_ref = test; // c++11 does reference collapse from rvalue ref to lvalue ref
	
	// The template type can be inferred in such a way that the function argument can be lvalue or rvalue, in order to
	// call the correct function (make sure the type of argument is correct), we need do "perfect forwarding"
	call(Test());
	call(test);

	return 0;
}
