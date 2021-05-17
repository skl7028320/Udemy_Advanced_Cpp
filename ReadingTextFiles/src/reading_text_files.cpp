/*
 * reading_text_files.cpp
 *
 *  Created on: 9 Mar 2021
 *      Author: libowen
 */

#include <iostream>
#include <fstream>

using namespace std;

int main() {
	string in_file_name = "text.txt";
	ifstream in_file;
	in_file.open(in_file_name);

	if (in_file.is_open()) {
		string line;

		//in_file >> line;
		//getline(in_file, line);
		while(in_file) {
			getline(in_file, line);
			cout << line << endl;
		}

		in_file.close();
	}
	else {
		cout << "Cannot open file: " << in_file_name << endl;
	}

	return 0;
}
