/*
 * the_auto_keyword.cpp
 *
 *  Created on: 14 Mar 2021
 *      Author: Bowen Li
 */

#include <iostream>

using namespace std;

template<typename T, class S>
auto test(T value1, S value2) -> decltype(value1 + value2) {
	return value1 + value2;
}

int get() {
	return 999;
}

auto test2() -> decltype(get()) {
	return get();
}

int main() {
	auto value = 7;
	auto text = "Hello";
	
	cout << value << endl;
	cout << text << endl;
	
	cout << test(5, 6) << endl;

	cout << test2() << endl;

	return 0;
}
