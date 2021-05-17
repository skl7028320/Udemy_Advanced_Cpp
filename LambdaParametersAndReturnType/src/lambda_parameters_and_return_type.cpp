/*
 * lambda_parameters_and_return_type.cpp
 *
 *  Created on: 17 Mar 2021
 *      Author: Bowen Li
 */

#include <iostream>

using namespace std;

void TestGreet(void (*ptr_func)(string)) {
	ptr_func("Mike");
}

void run_divide(double (*ptr_divide)(double, double)) {
	auto ret_value = ptr_divide(9, 3);
	cout << ret_value << endl;
}

int main() {
	auto ptr_greet = [](string name){ cout << "Hello " << name << endl; };
	
	ptr_greet("Bob");
	
	TestGreet(ptr_greet);
	//TestGreet([](string name){ cout << "Hello " << name << endl; });

	// No need for lambda expression to specify the return type, c++ can infer it automatically
	// But if there are multiple return types, lambda functions shall specify trailing return type
	auto ptr_divide = [](double a, double b) -> double {
		if (b == 0) {
			return 0;
		}
		return a / b;
	};

	cout << ptr_divide(10.0, 2.0) << endl;
	cout << ptr_divide(3.0, .0) << endl;

	run_divide(ptr_divide);

	return 0;
}
