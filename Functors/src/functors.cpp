/*
 * functors.cpp
 *
 *  Created on: 14 Mar 2021
 *      Author: Bowen Li
 */

#include <iostream>

using namespace std;

struct Test {
	virtual bool operator()(string &test) = 0;

	virtual ~Test() {}
};

// This is a functor. Functors are classes or structs that overload brackets operator.
struct MatchTest : public Test{
	virtual bool operator()(string &text) {
		return text == "lion";
	}
};

void check(string text, Test &test) {
	if (test(text)) {
		cout << "Test matches!" << endl;
	}
	else {
		cout << "No match." << endl;
	}
}

int main() {
	MatchTest pred;
	
	string value = "lion";

	MatchTest m;

	check("lion", m);
	
	return 0;
}
