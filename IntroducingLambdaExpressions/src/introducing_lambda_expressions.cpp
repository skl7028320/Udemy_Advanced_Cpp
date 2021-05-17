/*
 * introducing_lambda_expressions.cpp
 *
 *  Created on: 17 Mar 2021
 *      Author: Bowen Li
 */

#include <iostream>

using namespace std;

void test(void (*ptr_func)()) {
	ptr_func();
}

int main() {
	auto func = [](){ cout << "Hello" << endl; };

	test(func);

	test([](){ cout << "Hello again" << endl; });

	return 0;
}
