//
// Created by mushr on 2021/12/10.
//
#include <iostream>
#ifndef ALGORITHM_CPP_COURESE_2021_COMPLEX_H
#define ALGORITHM_CPP_COURESE_2021_COMPLEX_H
#include "../lib/complex.h"
#endif
#include "../utility.h"
#include "../Errors.h"
complex::complex(const string &input) {
    /**
     * scan from index 0 to index input size; record number range
     */
    int iposition = input.find('i');
    if (iposition == -1) {
        this->real = utility::to_double(input);
    } else {
        if (iposition == 0) {
            this->real = 0;
            this->vir = 1;
        } else {
            int povit(0);
            bool isNumber = false;
            for (int i = 0; i < input.length(); i++) {
                // start for loop
                if (input[i] == 'i') {
                    this->vir = utility::to_double(input.substr(povit, i - povit));
                }

                if (input[i] <= '9' && input[i] >= '0')
                    isNumber = true;

                if (isNumber && (input[i] == '-' || input[i] == '+')) {
                    this->real = utility::to_double(input.substr(povit, i));
                    povit = i;
                    isNumber = false;
                }
            }
            if (input[input.length() - 1] != 'i') {
                this->real = utility::to_double(input.substr(povit, input.length()));
            }
        }
    }
}

ostream &operator<<(ostream &os, complex &com) {
    os << "(" << com.real << "," << com.vir << "i)";
    return os;
}

istream &operator>>(istream &is, complex &com) {
    is >> com.real >> com.vir;
    return is;
}

complex &complex::operator+(complex &plus) {
    this->real += plus.real;
    this->vir += plus.vir;
    return *this;
}

complex &complex::operator+(double plus) {
    this->real += plus;
    return *this;
}

complex &complex::operator+(const string &plus) {
    complex buffer = plus;
    *this = *this + buffer;
    return *this;
}

complex &complex::operator-(const string &mius) {
    complex buffer = mius;
    *this = *this - buffer;
    return *this;
}

complex &complex::operator-(complex &mius) {
    this->real -= mius.real;
    this->vir -= mius.vir;
    return *this;
}

complex &complex::operator-(double mius) {
    this->real -= mius;
    return *this;
}

complex &complex::operator/(const string &div) {
    complex buffer = div;
    return *this / buffer;
}

complex &complex::operator/(complex &div) {
    double divide = div.real * div.real + div.vir * div.vir;
    double copyReal(this->real), copyVir(this->vir);
    this->real = (div.real * copyReal + div.vir * copyVir) / divide;
    this->vir = (div.real * copyVir - copyReal * div.vir) / divide;
    return *this;
}

complex &complex::operator/(double div) {
    if (!div) {
        throw ZeroDivide();
    }
    this->real /= div;
    this->vir /= div;
    return *this;
}

complex &complex::operator*(const string &times) {
    complex buffer = times;

    return *this * buffer;
}

complex &complex::operator*(complex &times) {
    double copyReal(this->real), copyVir(this->vir);

    this->real = (copyReal * times.real) - (copyVir * times.vir);
    this->vir = (copyReal * times.vir) + (copyVir * times.real);
    return *this;
}

complex &complex::operator*(double times) {
    complex buffer(times, 0);
    return *this * buffer;
}