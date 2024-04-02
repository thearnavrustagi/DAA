#ifndef COMPLEX_H
#define COMPLEX_H

#include <cmath>
#include <iostream>
using namespace std;

class Complex
{
private:
	double real, imag;

public:
	Complex();
	Complex(Complex&);
	Complex(double, double);
	Complex(char*);

	Complex operator-() const;

	inline double getReal() const;
	inline double setReal(double);

	inline double getImaginary() const;
	inline double setImaginary(double);
};

inline double norm(const Complex &complex)
{
	return abs(complex.getReal()) + abs(complex.getImaginary());
}

using namespace std;
inline std::ostream &operator<<(std::ostream &out, const Complex &complex)
{
	const char* symbol = (complex.getImaginary() < 0.0 ? "" : "+");
	return out << complex.getReal() << symbol << complex.getImaginary() << 'i';
}

inline Complex operator+(const Complex &a, const Complex &b)
{
	return Complex(a.getReal() + b.getReal(), a.getImaginary() + b.getImaginary());
}

inline Complex operator-(const Complex &a, const Complex &b)
{
	return Complex(a.getReal() - b.getReal(), a.getImaginary() - b.getImaginary());
}

inline bool operator<(const Complex &a, const Complex &b)
{
	double norm1 = norm(a);
	double norm2 = norm(b);

	return norm1 != norm2 ? norm1 < norm2 : a.getReal() != b.getReal() ? a.getReal() < b.getReal() : a.getImaginary() != b.getImaginary() ? a.getImaginary() < b.getImaginary() : 0;
}

inline bool operator>(const Complex &a, const Complex &b)
{
	double norm1 = norm(a);
	double norm2 = norm(b);

	return norm1 != norm2 ? norm1 > norm2 : a.getReal() != b.getReal() ? a.getReal() > b.getReal() : a.getImaginary() != b.getImaginary() ? a.getImaginary() > b.getImaginary() : 0;
}

#endif
