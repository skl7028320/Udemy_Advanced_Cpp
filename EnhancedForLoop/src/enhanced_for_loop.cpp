/*
 * enhanced_for_loop.cpp
 *
 *  Created on: 14 Mar 2021
 *      Author: Bowen Li
 */

#include <iostream>
#include <vector>

using namespace std;


int main() {
	string texts[] = {"one", "two", "three"};
	//auto texts = {"one", "two", "three"};
	
	for(auto &text : texts) {
		cout << text << endl;
	}

	vector<int> numbers;
	numbers.push_back(5);
	numbers.push_back(7);
	numbers.push_back(9);
	numbers.push_back(11);

	for (auto &number : numbers) {
		cout << number << endl;
	}

	string hello = "hello";

	for (auto c : hello) {
		cout << c << endl;
	}

	return 0;
}

