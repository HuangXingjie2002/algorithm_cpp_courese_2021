//
// Created by mushr on 2021/12/10.
//

#ifndef ALGORITHM_CPP_COURESE_2021_ERRORS_H
#define ALGORITHM_CPP_COURESE_2021_ERRORS_H
#include <iostream>
using namespace std;
struct ZeroDivide : public exception {
    string error() {
        return "Divided by Zero";
    }
};


#endif //ALGORITHM_CPP_COURESE_2021_ERRORS_H
