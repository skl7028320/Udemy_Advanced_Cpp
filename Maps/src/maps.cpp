/*
 * maps.cpp
 *
 *  Created on: 12 Mar 2021
 *      Author: libowen
 */

#include <iostream>
#include <map>

using namespace std;

int main() {
	map<string, int> ages;
	
	//pair<string, int> add_to_map("Peter", 100);
	//ages.insert(pair<string, int>("Peter", 100));
	ages.insert(make_pair("Peter", 100));

	ages["Mike"] = 30;
	ages["Raj"] = 20;
	ages["Vicky"] = 30;

	ages["Mike"] = 70;

	cout << ages["Sue"] << endl;

	cout << ages["Raj"] << endl;
	
	if (ages.find("Vicky") != ages.end()) {
		cout << "found Vicky!" << endl;
	}
	else{
		cout << "Key not found" << endl;
	}

	for (auto it = ages.begin(); it != ages.end(); it++) {
		pair<string, int> age = *it;

		cout << age.first << ", " << age.second << endl;
	}

	for (auto it = ages.begin(); it != ages.end(); it++) {
		cout << it->first << ", " << it->second << endl;
	}

	ages["Mike"];

	return 0;
}
