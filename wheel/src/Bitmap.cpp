//
// Created by mushr on 2021/12/6.
//
#include <iostream>
#ifndef BITMAP_CPP
#define BITMAP_CPP
#include "../lib/Bitmap.h"
#endif

Bitmap::Bitmap(MapSize size) {
    this->_size = size * 32;
    this->_bitset = new MapSize [_size];
    this->_bitset = (MapSize *) memset(this->_bitset, 0, _size * sizeof(MapSize));
}

bool Bitmap::test(int k) {
    // array Size is __size; first whether k is greater than __size * 64

    /**
     * we need to know where is the k of the mapsize array ?
     * we need to get index of k
     */
    /**
     * then we need to check where is k actually at ?
     */
    return _bitset[k >> 5] & (0x80000000 >> (k & 0x1F));
}

void Bitmap::set(int k) {
    /**
     * this is because 0x80 >> (k & 0x07) is mask ID, use and can make 0 -> 1 and 1 -> 1
     */
    _bitset[k >> 5] |= (0x80000000 >> (k & 0x1F));
}

void Bitmap::clear(int k) {
    _bitset[k >> 5] ^= (0x80000000 >> (k & 0x1F));
}

void Bitmap::expand(int k) {
    if (k > this->_size) {
        auto *newSpace = new MapSize [_size * 2];
        newSpace = (MapSize *)memset(newSpace, 0, sizeof(MapSize) * _size * 2);
        newSpace = (MapSize *)memcpy(newSpace, this->_bitset, _size);
        auto * old = this->_bitset;
        this->_bitset = newSpace;
        this->_size = 2 * _size;
        delete[] this->_bitset;
    }
}


