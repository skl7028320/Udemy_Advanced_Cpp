/*
 * multimaps.cpp
 *
 *  Created on: 12 Mar 2021
 *      Author: libowen
 */

#include <iostream>
#include <map>

using namespace std;

int main() {
	multimap<int, string> lookup;

	lookup.insert(make_pair(30, "Mike"));
	lookup.insert(make_pair(10, "Vicky"));
	lookup.insert(make_pair(30, "Raj"));
	lookup.insert(make_pair(20, "Bob"));
	
	for (auto it = lookup.begin(); it != lookup.end(); it++) {
		cout << it->first << ": " << it->second << endl;
	}
	
	cout << endl;

	for (auto it = lookup.find(20); it != lookup.end(); it++) {
		cout << it->first << ": " << it->second << endl;
	}

	cout << endl;

	//pair<multimap<int, string>::iterator, multimap<int, string>::iterator> its = lookup.equal_range(30);
	auto its = lookup.equal_range(30);

	for (auto it = its.first; it != its.second; it++) {
		cout << it->first << ": " << it->second << endl;
	}

	return 0;
}

