//
// Created by mushr on 2021/11/28.
//


#include <iostream>
#ifndef VECTOR_CPP
#define VECTOR_CPP

#include "../lib/Vector.h"

#endif


template<typename T>
Vector<T>::Vector(int c) {
    _elem  = new T[_capacity = c];
    _size = 0;
}


template<typename T>
Vector<T>::Vector(const T *array, Rank lo, Rank hi) {
    this->copyFrom(array, lo, hi);
}

template<typename T>
Vector<T>::Vector(Vector<T> &vec) {
    this->copyFrom(vec._elem, 0, vec._size);
}


template<typename T>
Vector<T>::Vector(Vector<T> &vec, Rank lo, Rank hi) {
    this->copyFrom(vec._elem, lo, hi);
}


template<typename T>
bool Vector<T>::copyFrom(const T *array, Rank lo, Rank hi) {
    // 注意这里hi是哨兵
    // 即 [lo, hi) -> batchSize = hi - lo;
    _elem = new T[_capacity = (hi - lo) * 2];
    bool flag = true;
    if (_elem) {
        _size = 0; // size
        while (lo < hi) {
            _elem[_size++] = array[lo++];
        }
//        或者使用下面的方法初始化
//        _size = hi - lo;
//        for (int i = _size - 1; i >= 0; i --) {
//            _elem[i] = array[--hi];
//        }
    } else {
        flag = false;
        std::cout << "初始化失败" << std::endl;
    }
    return flag;
}


// 小标运算符
template<typename T>
inline T & Vector<T>::operator[](Rank i) {
    return *(this->_elem + i);
}

// 扩大容量

template<typename T>
void Vector<T>::expand() {
    if (_size < _capacity) return;
    _capacity = _capacity > DEFAULT_SIZE ? _capacity : DEFAULT_SIZE;

    T * oldElem = _elem;
    _elem = new T[_capacity <<= 1];

    for (int i = 0; i < _size; i ++) {
        _elem[i] = oldElem[i];
    }
    delete[] oldElem;
}

template<typename T>

Rank Vector<T>::search(T target) {

    // 还需要判断是否是ordered！

    Rank lo(0), hi(this->_size), mid((lo + hi) >> 1);

    if (target <= this->operator[](0)) return 0;

    while (mid != lo) {
        if (this->operator[](mid) == target) {
            return mid;
        } else if (this->operator[](mid) < target) {
            lo = mid;
        } else {
            hi = mid;
        }
        mid = (lo + hi) >> 1;
    }

    return hi;
}