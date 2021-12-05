//
// Created by mushr on 2021/11/28.
//
#pragma once

#include <iostream>


// 寻秩访问

typedef int Rank; // 秩

template<typename T>
class Vector {
private:
    /**
     * 数据
     */


    int _size; // 当前大小
    int _capacity; // 总容量
    T *_elem; // 数据
    bool sorted; // whether vector is sorted
    static const int DEFAULT_SIZE = 3;

    void merge(Rank lo, Rank mi, Rank hi); // merge unit

    void bubbleSort(Rank lo, Rank hi);

    void mergeSort(Rank lo, Rank hi);
public:
    /**
     * 接口
     */

    Vector(int c = DEFAULT_SIZE, bool sorted = false);

    Vector(const T *array, Rank lo, Rank hi, bool sorted = false); // 从数组中复制

    Vector(Vector<T> &vec, bool sorted = false); // 从现有的vec中赋值

    Vector(Vector<T> &vec, Rank lo, Rank hi, bool sorted = false); // 从现有的向量中复制

    ~Vector() {
        delete[] _elem; // 释放
    }

    bool copyFrom(const T *array, Rank lo, Rank hi); // 从数组中复制

    T &operator[](Rank i); // inline function forbid for loop or recursive structure
    // reference T make it can put it at left position
    void expand();

    Rank size() { return this->_size; }

    Rank insert(Rank r, T value);

    void erase(Rank lo, Rank hi);

    T erase(Rank index); // single value delete

    Rank find(T value, Rank lo, Rank hi);

    Rank find(T value);

    int deduplicate();

    template<typename VST>
    void traverse(VST & visit);

    int disordered();  // back disordered pair num

    Rank search(T target); // sorted vector search

    Rank search(T target, Rank lo, Rank hi);

    void sort(Rank lo, Rank hi);

    void sort();
};
#ifndef VECTOR_CPP
#define VECTOR_CPP

#include "../src/Vector.cpp"
#endif