//
// Created by mushr on 2021/10/29.
//

#pragma once

template<typename T>
class Node {
public:
    T value;
    Node *left;
    Node *right;
};


template<typename T>
class binear_tree {
private:
    int size; // 当前树的节点数目
    int depth; // 当前树的深度
    int degree; // 当前树的度， 取max
    Node<T> *root;

public:
    binear_tree();
};


#ifndef BINEAR_TREE_CPP
#define BINEAR_TREE_CPP
#include "../src/binear_tree.cpp"
#endif
