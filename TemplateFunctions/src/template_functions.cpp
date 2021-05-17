/*
 * template_functions.cpp
 *
 *  Created on: 14 Mar 2021
 *      Author: Bowen Li
 */

#include <iostream>
#include "test.h"

using namespace std;
using namespace advanced_cpp;

//template<class T>
/*
template<typename T>
void print(T obj) {
	cout << obj << endl;
}
*/

int main() {
	print<string>("Hello");
	print<int>(5);
	
	print("Test");

	return 0;
}
