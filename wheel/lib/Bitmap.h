//
// Created by mushr on 2021/12/6.
//
#pragma once

#include <iostream>
#include <cstdlib>
#include <cstring>

#define MapSize unsigned int

class Bitmap {
    /**
     * a set for number
     */
private:
    // 8 byte, 64 bit
    // 4 byte, 32 bit
    MapSize _size;
    MapSize * _bitset;
public:
    // give size n -> N * 8 (N is byte)
    //             -> N = n / 8
    explicit Bitmap(MapSize size = 64);

    bool test(int k);

    void set(int k);

    void clear(int k);

    void expand(int k);
};

