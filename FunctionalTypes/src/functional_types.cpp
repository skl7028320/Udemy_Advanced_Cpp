/*
 * function_types.cpp
 *
 *  Created on: 17 Mar 2021
 *      Author: Bowen Li
 */

#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

using namespace std;

// Funciton ptr
bool check(string &test) {
	return test.size() == 3;
}

// Functor
class Check {
public:
	bool operator()(string &test) {
		return test.size() == 5;
	}
} check_functor;

// Using function template for callable type, e.g. lambda, functor and function ptr
void run(function<bool(string&)> check) {
	string test = "stars";
	cout << check(test) << endl;
}

int main() {
	vector<string> vec { "one", "two", "three" }; // @suppress("Invalid arguments")

	int size = 5;

	// Lambda function/expression
	auto lambda = [size](string test) {
		return test.size() == size;
	};
	int count = count_if(vec.begin(), vec.end(), lambda);
	/*
	 int count = count_if(vec.begin(), vec.end(), [size](string test) {
	 return test.size() == size;
	 });
	 */
	cout << count << endl;

	count = count_if(vec.begin(), vec.end(), check);
	cout << count << endl;

	count = count_if(vec.begin(), vec.end(), check_functor);
	cout << count << endl;

	run(lambda); // Passing lambda
	run(check_functor); // Passing functor
	run(check); // Passing function ptr

	// Callable type
	function<int(int, int)> add = [](int one, int two){
		return one + two;
	};
	cout <<  add(2, 3) << endl;

	return 0;
}
