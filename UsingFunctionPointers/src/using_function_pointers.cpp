/*
 * using_function_pointers.cpp
 *
 *  Created on: 14 Mar 2021
 *      Author: Bowen Li
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool match(string test) {
	return test.size() == 3;
}

int count_strings(vector<string> &texts, bool (*match)(string)) {
	int count = 0;

	for (auto &s : texts) {
		if (match(s)) {
			count++;
		}
	}

	return count;
}

int main() {
	vector<string> texts;
	
	texts.push_back("one");
	texts.push_back("two");
	texts.push_back("three");
	texts.push_back("four");
	texts.push_back("five");
	texts.push_back("six");
	
	cout << count_if(texts.begin(), texts.end(), match) << endl;

	cout << count_strings(texts, match) << endl;

	return 0;
}
