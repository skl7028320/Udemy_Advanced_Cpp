/*
 * sorting.cpp
 *
 *  Created on: 13 Mar 2021
 *      Author: libowen
 */

#include <iostream>
#include <vector>

using namespace std;

class Test {
	int id;
	string name;

public:
	Test(int id, string name) : id(id), name(name) {}

	void print() {
		cout << id << ": " << name << endl;
	}

	/*bool operator < (const Test &other) const {
		return name < other.name;
	}*/

	friend bool comp(const Test &a, const Test &b);
};

bool comp(const Test &a, const Test &b) {
	return a.name < b.name;
}

int main() {
	vector<Test> tests;
	
	tests.push_back(Test(5, "Bob"));
	tests.push_back(Test(3, "Billy"));
	tests.push_back(Test(10, "Amy"));
	tests.push_back(Test(1, "Mike"));
	
	for (auto test : tests) {
		test.print();
	}

	cout << endl;

	sort(tests.begin(), tests.end(), comp);

	for (auto test : tests) {
		test.print();
	}

	return 0;
}
