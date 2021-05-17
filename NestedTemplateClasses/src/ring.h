/*
 * ring.h
 *
 *  Created on: 15 Mar 2021
 *      Author: Bowen Li
 */

#ifndef SRC_RING_H_
#define SRC_RING_H_

#include <iostream>
#include <string>
#include <deque>

using namespace std;

namespace advanced_cpp {

template<typename T>
class ring {
private:
	int buf_size;
	deque<T> buf;

public:
	ring(int size) : buf_size(size) {}

	void add(T text) {
		if (buf.size() >= 3) {
			buf.pop_back();
			buf.push_front(text);
		}
		else {
			buf.push_front(text);
		}
	}

	T get(int i) {
		return buf.at(i);
	}

	int size() {
		return buf_size;
	}

	class iterator;
};

template<typename T>
class ring<T>::iterator {
public:
	void print() {
		cout << "Hello from iterator: " << T() << endl;
	}
};

} /* namespace advanced_cpp */

#endif /* SRC_RING_H_ */
