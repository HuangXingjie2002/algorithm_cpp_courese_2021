//
// Created by mushr on 2021/10/29.
//

/**
 * 使用链式存储使用一个结点处的三个指针分别指向左子树，右子树，父节点。
 *
 * 二叉树的存储方式，由于是非线性结构，所以插入的时候不是唯一插值，所以必须限制数据插入的规则确保唯一性。
 * 在有新的数据时会根据二叉树的规则进行数据的插入。
 *
 */

#pragma once

template<typename T>
class Node {
public:
    T value;
    Node *left; // 左子树
    Node *right; // 右子树
    Node *parent; // 父子树
};


template<typename T>
class tree_list {
private:
    int size; // 当前树的节点数目
    int depth; // 当前树的深度
    int degree; // 当前树的度， 取max
    Node<T> *root;

public:
    tree_list(); // 初始化一棵树结构
};


#ifndef TREE_LIST_CPP
#define TREE_LIST_CPP
#include "../src/binear_tree.cpp"
#endif
