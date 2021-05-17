/*
 * writing_text_files.cpp
 *
 *  Created on: 9 Mar 2021
 *      Author: libowen
 */

#include <iostream>
#include <fstream>>

using namespace std;

int main() {
	// ofstream out_file;

	fstream out_file;

	string out_file_name = "text.txt";

	// out_file.open(out_file_name);
	out_file.open(out_file_name, ios::out);

	if (out_file.is_open()) {
		out_file << "Hello there" << endl;
		out_file << 123 << endl;

		out_file.close();
	}
	else {
		cout << "Could not create file: " << out_file_name << endl;
	}

	return 0;
}
