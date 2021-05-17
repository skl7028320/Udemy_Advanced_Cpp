/*
 * binary_files.cpp
 *
 *  Created on: 11 Mar 2021
 *      Author: libowen
 */

#include <iostream>
#include <fstream>

using namespace std;

#pragma pack(push, 1)

struct Person {
	char name[50];
	int age;
	double height;
};

#pragma pack(pop)

int main() {
	// Write binary file
	Person someone = {"Frodo", 220, 0.8};

	string filename = "test.bin";

	fstream output_file;

	output_file.open(filename, ios::binary|ios::out);

	if (output_file.is_open()) {
		output_file.write(reinterpret_cast<char *>(&someone), sizeof(Person));

		output_file.close();
	}
	else {
		cout << "Could not create file: " << filename << endl;
	}

	// Read binary file
	Person someone_else = {};

	fstream input_file;

	input_file.open(filename, ios::binary|ios::in);

	if (input_file.is_open()) {
		input_file.read(reinterpret_cast<char *>(&someone_else), sizeof(Person));

		input_file.close();
	}
	else {
		cout << "Could not read file: " << filename << endl;
	}

	cout << someone_else.name << ", " << someone_else.age << ", " << someone_else.height << endl;

	return 0;
}
