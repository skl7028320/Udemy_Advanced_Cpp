/*
 * Complex.cpp
 *
 *  Created on: 13 Mar 2021
 *      Author: Bowen Li
 */

#include "Complex.h"
#include <iostream>

using namespace std;
namespace advanced_cpp {

ostream& operator<<(ostream &out, const Complex &complex) {
	return out << "(" << complex.get_real() << ", " << complex.get_imaginary()
			<< ")";
}

Complex::Complex() :
		real(0), imaginary(0) {
}

Complex::Complex(double real, double imaginary) :
		real(real), imaginary(imaginary) {
}

Complex::Complex(const Complex &other) {
	cout << "Copy constructor running!" << endl;

	real = other.real;
	imaginary = other.imaginary;
}

const Complex& Complex::operator=(const Complex &other) {
	cout << "Copy assignment operator running!" << endl;

	real = other.real;
	imaginary = other.imaginary;

	return *this;
}

} /* namespace advanced_cpp */
