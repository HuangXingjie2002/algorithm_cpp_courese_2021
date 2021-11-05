//
// Created by mushr on 2021/10/29.
//

#include <iostream>
#ifndef TREE_LIST_CPP
#define TREE_LIST_CPP
#include "../lib/tree_list.h"
#endif



template <typename T>
tree_list<T>::tree_list() {
    this->size = 0;
    this->degree = 0;
    this->depth = 0;
    this->root = NULL;
}


