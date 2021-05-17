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
};

ostream& operator<<(ostream &out, const Complex &complex);

} /* namespace advanced_cpp */

#endif /* SRC_COMPLEX_H_ */
