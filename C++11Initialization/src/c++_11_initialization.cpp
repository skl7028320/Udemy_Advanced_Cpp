/*
 * c++_11_initialization.cpp
 *
 *  Created on: 15 Mar 2021
 *      Author: Bowen Li
 */

#include <iostream>
#include <vector>

using namespace std;

int main() {
	// When using curly braces to initialize variable in C++ 11, there is no need for equal sign
	int value { 5 };
	cout << value << endl;

	string text { "hello" };
	cout << text << endl;

	// It also works with array
	int numbers[] { 1, 2, 3 };
	cout << numbers[1] << endl;

	// It also works with new (allocated memory)
	int *p_int = new int[3] { 1, 2, 3 };
	cout << p_int[2] << endl;
	delete[] p_int;

	// It also works with ptrs
	int *p_something { &value };
	cout << *p_something << endl;

	// Empty curly braces mean that variable is initialized by the default value of the type
	int value2 { };
	cout << value2 << endl;

	int *ptr { };
	//int *ptr{NULL}; // C++98
	//int *ptr{nullptr}; // C++11
	cout << ptr << endl;

	int numbers2[5] { };
	cout << numbers2[1] << endl;

	// It also works with custom class/struct
	struct {
		int id; // Initializing member in struct/class will make brace initialization no work
			    // because of the automatically deleted default constructor
		string text;
	} s1 { 5, "test" };
	cout << s1.text << endl;

	// Easy way of initializing vector
	vector<string> strings{"one", "tow", "three"}; // @suppress("Invalid arguments")
	cout << strings.at(2) << endl;

	return 0;
}
