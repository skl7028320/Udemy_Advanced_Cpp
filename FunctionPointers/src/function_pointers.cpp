/*
 * function_pointers.cpp
 *
 *  Created on: 14 Mar 2021
 *      Author: Bowen Li
 */

#include <iostream>

using namespace std;

void test(int value) {
	cout << "Hello: " << value << endl;
}

int main() {
	test(7);
	
	/*
	void (*p_test)(int);

	p_test = &test;

	(*p_test)();
	*/

	//auto p_test = test;
	void (*p_test)(int) = test;

	p_test(8);



	return 0;
}
