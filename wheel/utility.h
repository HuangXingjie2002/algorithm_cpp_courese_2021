//
// Created by mushr on 2021/11/6.
//

#ifndef ALGORITHM_CPP_COURESE_2021_UTILITY_H
#define ALGORITHM_CPP_COURESE_2021_UTILITY_H
#include "iostream"
#include "./lib/Log.h"
using namespace std;

template <typename T>
class utility {

};


/**
 *
 * @param n 传入栈的有多少个不同的数
 * @return 返回这些数经过栈处理后弹出的组合数
 */
long stack_num(int n);

string recLCS(string A, string B);

int dpLCS(string A, string B);

int* range(int begin, int end);

template <typename T>
void Swap(T &a, T &b);

#endif //ALGORITHM_CPP_COURESE_2021_UTILITY_H
