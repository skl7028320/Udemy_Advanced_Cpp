/*
 * custom_objects_as_map_values.cpp
 *
 *  Created on: 12 Mar 2021
 *      Author: libowen
 */

#include <iostream>
#include <map>

using namespace std;

class Person {
private:
	string name;
	int age;

public:
	Person() : name(""), age(0) {}

	Person(const Person &other) {
		cout << "Copy constructor running!" << endl;

		name = other.name;
		age = other.age;
	}

	Person(string name, int age) : name(name), age(age) {}

	void print() {
		cout << name << ": " << age << endl;
	}
};

int main() {
	map<int, Person> people;

	people[0] = Person("Mike", 40);
	people[6] = Person("Vicky", 30);
	people[3] = Person("Raj", 20);

	people.insert(make_pair(8, Person("Bob", 24)));
	people.insert(make_pair(9, Person("Billy", 17)));

	for (auto it = people.begin(); it != people.end(); it++) {
		cout << it->first << ": " << flush;
		it->second.print();
	}
	
	return 0;
}

