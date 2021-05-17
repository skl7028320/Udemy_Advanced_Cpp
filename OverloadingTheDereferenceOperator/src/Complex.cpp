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

Complex operator+(const Complex &c1, const Complex &c2) {
	return Complex(c1.get_real() + c2.get_real(), c1.get_imaginary() + c2.get_imaginary());
}

Complex operator+(const Complex &c, const double d) {
	return Complex(c.get_real() + d, c.get_imaginary());
}

Complex operator+(const double d, const Complex &c) {
	return Complex(c.get_real() + d, c.get_imaginary());
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

bool Complex::operator==(const Complex &other) const {
	return real == other.real && imaginary == other.imaginary;
}

bool Complex::operator!=(const Complex &other) const {
	return !(*this == other);
}

Complex Complex::operator*() const {
	return Complex(real, -imaginary);
}

} /* namespace advanced_cpp */
