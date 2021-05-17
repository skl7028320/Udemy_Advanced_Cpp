/*
 * Complex.h
 *
 *  Created on: 13 Mar 2021
 *      Author: Bowen Li
 */

#ifndef SRC_COMPLEX_H_
#define SRC_COMPLEX_H_

#include <iostream>

using namespace std;

namespace advanced_cpp {

class Complex {
private:
	double real;
	double imaginary;

public:
	Complex();

	Complex(double real, double imaginary);

	// Copy constructor
	Complex(const Complex &other);

	// Copy assignment operator
	const Complex& operator=(const Complex &other);

	double get_real() const {
		return real;
	}

	double get_imaginary() const {
		return imaginary;
	}

	bool operator==(const Complex &other) const;
	bool operator!=(const Complex &other) const;
};

ostream& operator<<(ostream &out, const Complex &complex);
Complex operator+(const Complex &c1, const Complex &c2);
Complex operator+(const Complex &c, const double d);
Complex operator+(const double d, const Complex &c);

} /* namespace advanced_cpp */

#endif /* SRC_COMPLEX_H_ */
