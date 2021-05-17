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
	T *m_values;
	int m_size;
	int m_pos;

public:
	class iterator;

public:
	ring(int size) : m_values(NULL), m_size(size), m_pos(0) {
		m_values = new T[size];
	}

	~ring() {
		delete[] m_values;
	}

	void add(T value) {
		m_values[m_pos++] = value;

		if (m_pos == m_size) {
			m_pos = 0;
		}
	}

	T& get(int i) {
		return m_values[i];
	}

	int size() {
		return m_size;
	}
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
