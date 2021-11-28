//
// Created by mushr on 2021/11/28.
//
#pragma once
#include <iostream>


// 寻秩访问

typedef int Rank; // 秩

template <typename T> class Vector {
private:
    /**
     * 数据
     */


    int _size; // 当前大小
    int _capacity; // 总容量
    T* _elem; // 数据

    static const int DEFAULT_SIZE = 3;
public:
    /**
     * 接口
     */

    Vector(int c = DEFAULT_SIZE);

    Vector(const T *array, Rank lo, Rank hi); // 从数组中复制

    Vector(Vector<T> &vec); // 从现有的vec中赋值

    Vector(Vector<T> &vec, Rank lo, Rank hi); // 从现有的向量中复制

    ~Vector() {
        delete[] _elem; // 释放
    }

    bool copyFrom(const T * array, Rank lo, Rank hi); // 从数组中复制

    T & operator[](Rank i);

    void expand();

    Rank size() { return this->_size; }

    Rank search(T target);
};















#ifndef VECTOR_CPP
#define VECTOR_CPP

#include "../src/Vector.cpp"

#endif