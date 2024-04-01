#include "../include/complex.hpp"

Complex::Complex() : real(0.0), imag(0.0) {}

Complex::Complex(Complex& other) {
	real = other.real;
	imag = other.imag;
}

Complex::Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

Complex::Complex(char* fmtstr) {
	int parsing_real= 1;
	int decimal_mode = 0;

	double parsed_real_int=0.0;
	double parsed_real_dbl=0.0;

	double parsed_imag_int=0.0;
	double parsed_imag_dbl=0.0;
	char sign;

	for (char* itr = fmtstr;*itr != '\0';itr++) {
		if (*itr == '+' || *itr == '-') {
			sign = *itr;
			parsing_real = 0;
			decimal_mode = 0;
			continue;
		}
		if (*itr == '.') {
			decimal_mode = 1;
			continue;
		}
		if (*itr > '9' || *itr < '0') continue;
		if (parsing_real) {
			if (!decimal_mode) {
				parsed_real_int = parsed_real_int*10 + (double)(*itr - '0');
			} else {
				parsed_real_dbl = parsed_real_dbl/10 + (double)(*itr - '0');
			}
		} else {
			if (!decimal_mode) {
				parsed_imag_int = parsed_imag_int*10 + (double)(*itr - '0');
			} else {
				parsed_imag_dbl = parsed_imag_dbl/10 + (double)(*itr - '0');
			}
		}
	}

	real = parsed_real_int + parsed_real_dbl/10;
	imag = (parsed_imag_int + parsed_imag_dbl/10) * (sign == '-'?-1:1);
}

Complex Complex::operator-() const
{
	return Complex(-getReal(), -getImaginary());
}

inline double Complex::getReal() const
{
	return real;
}

inline double Complex::setReal(double value) 
{
	return real = value;
}

inline double Complex::getImaginary() const
{
	return imag;
}

inline double Complex::setImaginary(double value) 
{
	return imag = value;
}