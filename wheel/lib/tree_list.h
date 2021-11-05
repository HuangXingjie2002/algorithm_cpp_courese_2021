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
class tree_list {
private:
    int size; // 当前树的节点数目
    int depth; // 当前树的深度
    int degree; // 当前树的度， 取max
    Node<T> *root;

public:
    tree_list();
};


#ifndef TREE_LIST_CPP
#define TREE_LIST_CPP
#include "../src/binear_tree.cpp"
#endif
