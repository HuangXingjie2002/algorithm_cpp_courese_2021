//
// Created by mushr on 2021/12/10.
//
#pragma once

#include <iostream>

using namespace std;


class complex {
private:
    double real{}; // 实部
    double vir{}; // 虚部

public:
    complex(double real = 0, double vir = 0) : real(real), vir(vir) { ; }

    complex(const string &input);

    complex(initializer_list<double> vec) {
        if (vec.begin() == vec.end()) {
            complex();
        }
        auto iter = vec.begin();
        real = *iter;
        vir = *(iter + 1);
    }

    friend ostream &operator<<(ostream &os, complex &com);

    friend istream &operator>>(istream &is, complex &com);


    // plus
    complex &operator+(const string &plus);

    complex &operator+(complex & plus);

    complex &operator+(double plus);

    // minus
    complex &operator-(const string &plus);

    complex &operator-(complex & plus);

    complex &operator-(double plus);

    // divide
    complex &operator/(const string &plus);

    complex &operator/(complex & plus);

    complex &operator/(double plus);

    // times
    complex &operator*(const string &times);

    complex &operator*(complex & times);

    complex &operator*(double times);
};
