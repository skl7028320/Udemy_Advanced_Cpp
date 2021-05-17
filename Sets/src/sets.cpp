/*
 * sets.cpp
 *
 *  Created on: 13 Mar 2021
 *      Author: libowen
 */

#include <iostream>
#include <set>

using namespace std;

class Person {
private:
	string name;
	int age;

public:
	Person(string name, int age) : name(name), age(age) {}

	void print() const {
		cout << name << ": " << age << flush;
	}

	bool operator < (const Person &other) const {
		return age < other.age;
	}
};

int main() {
	set<int> numbers;
	
	numbers.insert(1);
	numbers.insert(3);
	numbers.insert(2);

	for (auto element : numbers) {
		cout << element << endl;
	}
	
	set<int>::iterator it = numbers.find(5);
	if (it != numbers.end()) {
		cout << "Found " << *it << "!" << endl;
	}

	if (numbers.count(2)) {
		cout << "Number found!" << endl;
	}

	cout << endl;

	set<Person> people;

	people.insert(Person("Bob", 20));
	people.insert(Person("Alice", 10));
	people.insert(Person("Amy", 30));

	for (auto it = people.begin(); it != people.end(); it++) {
		it->print();

		cout << endl;
	}

	return 0;
}

