#ifndef SWAP_H
#define SWAP_H

inline double swap(Complex& a, Complex& b) {
    Complex temp = a;
    a = b;
    b = temp;
}

#endif