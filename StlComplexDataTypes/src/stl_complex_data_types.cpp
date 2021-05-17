/*
 * stl_complex_data_types.cpp
 *
 *  Created on: 13 Mar 2021
 *      Author: libowen
 */

#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
	map<string, vector<int> > scores;
	
	scores["Mike"].push_back(10);
	scores["Mike"].push_back(20);
	scores["Vicky"].push_back(50);

	for (auto it = scores.begin(); it != scores.end(); it++) {
		string name = it->first;
		vector<int> score_list = it->second;

		cout << name << ": " << flush;

		for (auto &score : score_list) {
			cout << score << " " << flush;
		}

		cout << endl;
	}

	return 0;
}
