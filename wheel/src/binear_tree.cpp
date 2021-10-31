//
// Created by mushr on 2021/10/29.
//

#include <iostream>
#ifndef BINEAR_TREE_CPP
#define BINEAR_TREE_CPP
#include "../lib/binear_tree.h"
#endif



template <typename T>
binear_tree<T>::binear_tree() {
    this->size = 0;
    this->degree = 0;
    this->depth = 0;
    this->root = NULL;
}


