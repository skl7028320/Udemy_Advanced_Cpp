/*
 * vectors.cpp
 *
 *  Created on: 11 Mar 2021
 *      Author: libowen
 */

#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<string> strings;

	strings.push_back("one");
	strings.push_back("two");
	strings.push_back("three");
	
	for (int i = 0; i < strings.size(); i++) {
		cout << strings[i] << endl;
	}

	for (vector<string>::iterator it = strings.begin(); it != strings.end(); it++) {
		cout << *it << endl;
	}

	// After C++ 11
	for (auto &element : strings) {
		cout << element << endl;
	}



	return 0;
}

