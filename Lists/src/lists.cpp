/*
 * lists.cpp
 *
 *  Created on: 12 Mar 2021
 *      Author: libowen
 */

#include <iostream>
#include <list>

using namespace std;

int main() {
	list<int> numbers;
	
	numbers.push_back(1);
	numbers.push_back(2);
	numbers.push_back(3);
	numbers.push_front(0);
	
	list<int>::iterator it = numbers.begin();
	it++;
	numbers.insert(it, 100);
	cout << "Element: " << *it << endl;

	list<int>::iterator erase_it = numbers.begin();
	erase_it++;
	erase_it = numbers.erase(erase_it);
	cout << "Element: " << *erase_it << endl;

	/*
	for (list<int>::iterator it = numbers.begin(); it != numbers.end();) {
		if (*it == 2) {
			numbers.insert(it, 1234);
		}
		if (*it == 1) {
			it = numbers.erase(it);
		}
		else {
			it++;
		}
	}
	*/

	auto loop_it = numbers.begin();
	while (loop_it != numbers.end()) {
		if (*loop_it == 2) {
			numbers.insert(loop_it, 1234);
		}

		if (*loop_it == 1) {
			loop_it = numbers.erase(loop_it);
		}
		else {
			loop_it++;
		}
	}

	for (list<int>::iterator it = numbers.begin(); it != numbers.end(); it++) {
		cout << *it << endl;
	}

	return 0;
}

