/*
 * stack_and_queue.cpp
 *
 *  Created on: 13 Mar 2021
 *      Author: libowen
 */

#include <iostream>
#include <stack>
#include <queue>

using namespace std;

class Test {
private:
	string name;

public:
	Test(string name) : name(name) {}

	~Test() {
		//cout << "Object destroyed" << endl;
	}

	void print() {
		cout << name << endl;
	}
};

int main() {
	// LIFO
	stack<Test> test_stack;
	
	test_stack.push(Test("Mike"));
	test_stack.push(Test("John"));
	test_stack.push(Test("Sue"));

	/*
	 * This is invalid code! Object is destroyed!
	Test &test1 = test_stack.top();
	test_stack.pop();
	test1.print(); // Reference refers to destroyed object!
	*/

	while (test_stack.size() > 0) {
		Test &test1 = test_stack.top();
		test1.print();
		test_stack.pop();
	}

	cout << endl;

	// FIFO
	queue<Test> test_queue;

	test_queue.push(Test("Mike"));
	test_queue.push(Test("John"));
	test_queue.push(Test("Sue"));

	/*
	 * This is invalid code! Object is destroyed!
	Test &test1 = test_stack.front();
	test_stack.pop();
	test1.print(); // Reference refers to destroyed object!
	*/

	test_queue.back().print();

	cout << endl;

	while (test_queue.size() > 0) {
		Test &test1 = test_queue.front();
		test1.print();
		test_queue.pop();
	}

	return 0;
}
