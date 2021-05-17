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
	ring(int size) :
			m_values(NULL), m_size(size), m_pos(0) {
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

	iterator begin() {
		return iterator(0, *this);
	}

	iterator end() {
		return iterator(m_size, *this);
	}
};

template<typename T>
class ring<T>::iterator {
private:
	int m_pos;
	ring &m_ring;

public:
	iterator(int pos, ring &arg_ring) :
			m_pos(pos), m_ring(arg_ring) {
	}

	iterator& operator++(int) {
		m_pos++;

		return *this;
	}

	iterator& operator++() {
		m_pos++;

		return *this;
	}

	T &operator*() {
		return m_ring.get(m_pos);
	}

	bool operator!=(const iterator &other) const {
		return m_pos != other.m_pos;
	}
};

} /* namespace advanced_cpp */

#endif /* SRC_RING_H_ */
