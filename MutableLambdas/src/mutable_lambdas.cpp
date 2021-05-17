/*
 * mutable_lambdas.cpp
 *
 *  Created on: 17 Mar 2021
 *      Author: Bowen Li
 */

#include <iostream>

using namespace std;

int main() {
	int cats = 5;
	
	// With mutable keyword, captured local variable by value can be changed
	[cats]() mutable {
		cats = 8;
		cout << cats << endl;
	}();
	
	// The original local variable stays unchanged, only the copy in Lambda function has been changed
	cout << cats << endl;

	return 0;
}
