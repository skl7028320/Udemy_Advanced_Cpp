/*
 * bind.cpp
 *
 *  Created on: 21 Mar 2021
 *      Author: Bowen Li
 */

#include <iostream>
#include <functional>

using namespace std;
using namespace placeholders;

class Test {
public:
	int add(int a, int b, int c) {
		cout << a << ", " << b << ", " << c << endl;

		return a + b + c;
	}
};

int add(int a, int b, int c) {
	cout << a << ", " << b << ", " << c << endl;

	return a + b + c;
}

int run(function<int(int, int)> func) {
	return func(7, 3);
}

int main() {
	// Bind makes an alias to a function with specified arguments
	function<int()> calculate = bind(add, 3, 4, 5); // @suppress("Invalid arguments") // @suppress("Function cannot be resolved")
	//auto calculate = bind(add, 3, 4, 5); // @suppress("Function cannot be resolved")
	cout << calculate() << endl; // @suppress("Invalid overload")

	// Place holders can be used so that arguments can be supplied when calling the function through alias
	function<int(int, int, int)> calculate2 = bind(add, _1, _2, _3); // @suppress("Invalid arguments") // @suppress("Function cannot be resolved")
	//auto calculate2 = bind(add, _1, _2, _3); // @suppress("Function cannot be resolved")
	cout << calculate2(10, 20, 30) << endl; // @suppress("Invalid overload")

	// The order of place holders can be changed
	auto calculate3 = bind(add, _2, _3, _1); // @suppress("Function cannot be resolved")
	cout << calculate3(10, 20, 30) << endl; // @suppress("Invalid overload")

	// Place holders and specified arguments can be mixed
	auto calculate4 = bind(add, _2, 100, _1); // @suppress("Function cannot be resolved")
	cout << calculate4(10, 20) << endl; // @suppress("Invalid overload")

	// Binded function can be used as argument to another function
	cout << run(calculate4) << endl; // @suppress("Invalid arguments") // @suppress("Invalid overload")

	// Method can also be binded
	Test test;
	auto calculate5 = bind(&Test::add, test, _2, 100, _1); // @suppress("Function cannot be resolved")
	cout << run(calculate5) << endl; // @suppress("Invalid arguments") // @suppress("Invalid overload")

	return 0;
}
