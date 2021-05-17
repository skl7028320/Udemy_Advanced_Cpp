/*
 * capturing_this_with_lambdas.cpp
 *
 *  Created on: 17 Mar 2021
 *      Author: Bowen Li
 */

#include <iostream>

using namespace std;

class Test {
private:
	int one{1};
	int two{2};

public:
	void run() {
		int three{3};
		int four{4};

		auto ptr_lambda = [this, three, four](){
			one = 111; // "this" is captured always by reference so we can change the instance variables

			cout << one << endl;
			cout << two << endl;
			cout << three << endl;
			cout << four <<endl;
		};
		ptr_lambda();
	}
};

int main() {
	Test test;
	test.run();
	
	return 0;
}

