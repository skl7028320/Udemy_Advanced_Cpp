/*
 * c++_98_initialization.cpp
 *
 *  Created on: 15 Mar 2021
 *      Author: Bowen Li
 */

#include <iostream>
#include <vector>

using namespace std;

int main() {
	int values[] = {1, 2, 3, 4};
	cout << values[0] << endl;

	// By default class has private members
	class C1 {
	public:
		string text;
		int id;
	};

	C1 c1 = {"hello", 7};
	cout << c1.text << endl;
	
	// By default struct has public members
	struct S1 {
		string text;
		int id;
	};

	S1 s1 = {"hello", 7};
	cout << c1.id << endl;
	
	// declare and initialize struct right after type definition
	struct S2 {
		string text;
		int id;
	} s2 = {"hello", 7};

	cout << s2.text << endl;

	// No need for type name if not used afterwards
	struct {
		string text;
		int id;
	} s3 = {"hello", 7}, s4 = {"bye", 5};

	cout << s4.text << endl;

	// Initialize vector with C++ 98
	vector<string> strings;

	strings.push_back("One");
	strings.push_back("Two");
	strings.push_back("Three");

	return 0;
}
