//
// Created by mushr on 2021/11/28.
//


#include <iostream>
#include "../utility.h"

#ifndef VECTOR_CPP
#define VECTOR_CPP

#include "../lib/Vector.h"

#endif


template<typename T>
Vector<T>::Vector(int c, bool sorted) {
    _elem = new T[_capacity = c];
    _size = c;
    this->sorted = sorted;
}


template<typename T>
Vector<T>::Vector(const T *array, Rank lo, Rank hi, bool sorted) {

    this->copyFrom(array, lo, hi);
    this->sorted = sorted;
}

template<typename T>
Vector<T>::Vector(Vector<T> &vec, bool sorted) {
    this->copyFrom(vec._elem, 0, vec._size);
    this->sorted = sorted;
}


template<typename T>
Vector<T>::Vector(Vector<T> &vec, Rank lo, Rank hi, bool sorted) {
    this->copyFrom(vec._elem, lo, hi);
    this->sorted = sorted;
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
inline T &Vector<T>::operator[](Rank i) {
    /**
     * @param i: vector index
     * @return reference of vector element
     */
    return *(this->_elem + i);
}

// 扩大容量

template<typename T>
void Vector<T>::expand() {
    if (_size < _capacity) return;
    _capacity = _capacity > DEFAULT_SIZE ? _capacity : DEFAULT_SIZE;

    T *oldElem = _elem;
    _elem = new T[_capacity <<= 1];

    for (int i = 0; i < _size; i++) {
        _elem[i] = oldElem[i];
    }
    delete[] oldElem;
}

template<typename T>

Rank Vector<T>::search(T target) {

    // 还需要判断是否是ordered！
    return this->search(target, 0, this->size());
}


template<typename T>
Rank Vector<T>::insert(Rank r, T value) {
    expand(); // check if we need expand capacity
    // insert
//    T buffer;
//    for (int i = r; i < _size; i ++) {
//        buffer = _elem[i];
//        _elem[i] = value;
//        value = buffer;
//    }
//    _elem[_size++] = buffer;
//    return r;
    // forecast will be difficult

    for (int i = _size; i > r; i--) {
        _elem[i] = _elem[i - 1];
    }
    _elem[r] = value;
    _size++;
    return r;
}


template<typename T>
void Vector<T>::erase(Rank lo, Rank hi) {
    // copy
    if (lo >= hi) return;
    while (hi < _size) {
        _elem[lo++] = _elem[hi++];
    }
    _size -= hi - lo;
}

template<typename T>
T Vector<T>::erase(Rank index) {
    T elem = _elem[index];
    erase(index, index + 1);
    return elem;
}

template<typename T>
Rank Vector<T>::find(T value, Rank lo, Rank hi) {
    while (lo < hi) {
        if (_elem[lo++] == value) {
            return lo - 1;
        }
    }
    return -1;
}

template<typename T>
Rank Vector<T>::find(T value) {
    return find(value, 0, _size);
}

template<typename T>
int Vector<T>::deduplicate() {
    // deduplicate
    int oldSize = _size;
    if (sorted) {
        // if vector was sorted
//        T first = _elem[0];
//        Rank start = 0;
//        for (Rank i = 0; i < _size;) {
//            if (first == _elem[i]) {
//                i ++;
//            } else {
//                erase(start+1, i);
//                i -= i - start - 1;
//                start = i; // different
//                first = _elem[i];
//            }
//        }
        int beginIndex = 0, cycle = 0;
        while (cycle != _size) {
            if (_elem[cycle] != _elem[beginIndex]) {
                _elem[++beginIndex] = _elem[cycle];
            }
            cycle++;
        }
        _size = beginIndex + 1;
    } else {
        Rank lo = 1;
        Rank index;
        while (lo < _size) {
            index = find(_elem[lo], 0, lo);
            if (_elem[index] == _elem[lo]) {
                erase(index); // delete if find
                lo--; // update to original position
            }
            lo++;
        }
    }

    return oldSize - _size;

    //
}

template<typename T>
template<typename VST>
void Vector<T>::traverse(VST &visit) {
    for (int i = 0; i < _size; i++) {
        _elem[i] = visit(_elem[i]);
    }
}

template<typename T>
int Vector<T>::disordered() {
    int n(0), i(1);
    if (_size > 1) {
        while (i < _size) {
            n += (_elem[i - 1] > _elem[i++]);
        }
    }
    return n;
}

template<typename T>
Rank Vector<T>::search(T target, Rank lo, Rank hi) {

    Rank mid;
    while (lo < hi) {
        mid = (lo + hi) >> 1;
        (target < _elem[mid]) ? hi = mid : lo = mid + 1;
    }
    return --lo;
}

template<typename T>
void Vector<T>::sort(Rank lo, Rank hi) {
    /**
     * bubble Sort
     */

    mergeSort(lo, hi);

    sorted = true;

    /**
     * merge sort
     */
}


template<typename T>
void Vector<T>::sort() {
    sort(0, this->size());
}

template<typename T>
void Vector<T>::mergeSort(Rank lo, Rank hi) {
    if (hi - lo < 2) return; // if interval less than 2, then return
    Rank mi = (hi + lo) >> 1;
    mergeSort(lo, mi);
    mergeSort(mi, hi);
    /**
     * 0 1 2 -> [0 1] [2 2]
     * [0 1] -> [0 0] [1 1] -> return, return
     * [2 2] -> return
     *
     * merge
     * [0 0] [1 1] (0 0 1)-> if (hi - lo = 1) swap
     * [0 1] [2 2] (0 1 2)-> [0 1] [2] if select the min one copy to and index ++
     */
    merge(lo, mi, hi);
}

template<typename T>
void Vector<T>::merge(Rank lo, Rank mi, Rank hi) {
    T buffer[hi - lo + 1];

    Rank indexI(lo), indexII(mi);
    Rank bufferIndex(0);
    // [0 0] [1 1]
    // build another mi to hi array

    while (indexI < mi && indexII < hi) {
        if (_elem[indexI] <= _elem[indexII]) {
            buffer[bufferIndex++] = _elem[indexI++];
        } else {
            buffer[bufferIndex++] = _elem[indexII++];
        }
    }

    if (indexII == hi && indexI < mi) {
        while (indexI < mi) {
            buffer[bufferIndex++] = _elem[indexI++];
        }
    } else if (indexI == mi && indexII < hi) {
        while (indexII < hi) {
            buffer[bufferIndex++] = _elem[indexII++];
        }
    }

    for (int i = 0; i < bufferIndex; i++) {
        _elem[i+lo] = buffer[i];
    }
}

template<typename T>
void Vector<T>::bubbleSort(Rank lo, Rank hi) {
    bool isSorted = true;
    Rank furthestIndex = hi;
    while (hi - lo > 1) {
        for (int i = lo+1; i < hi; i ++) {
            if (_elem[i-1] > _elem[i]) {
                swap(_elem[i-1], _elem[i]);
                isSorted = false;
                furthestIndex = i;
            }
        }
        hi = furthestIndex;
        // insert a furthest to record the last unsorted pair index, next time will end there
        if (isSorted) {
            break;
        }
    }
}
