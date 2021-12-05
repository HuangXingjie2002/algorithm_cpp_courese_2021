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


typedef struct tree {
    char value;
    struct tree *left;
    struct tree *right;
} T;

T *createTree(const std::string &first, const std::string &center) {
    /**
     * 从先序中取值
     */

    if (first.length() == 0 || center.length() == 0) {
        return nullptr;
    }

    char head = first[0]; // 从先序中取第一个元素
    int indexInCenter = center.find(head); // 从中序中发现先序头字母出现的位置
    T * node = new T;
    node -> value = head;

    std::string centerLeft = center.substr(0, indexInCenter);
    std::string centerRight = center.substr(indexInCenter + 1, center.length());

    std::string firstLeft = first.substr(1, centerLeft.length());
    std::string firstRight = first.substr(centerLeft.length() + 1, centerRight.length());

    node->left = createTree(firstLeft, centerLeft);
    node->right = createTree(firstRight, centerRight);

    return node;
}

void treeShowAfter(T * tree, std::string &s) {
    if (tree->left != NULL) {
        treeShowAfter(tree->left, s);
    }

    if (tree->right != NULL) {
        treeShowAfter(tree->right, s);
    }

    s += tree->value;
}

#ifndef TREE_LIST_CPP
#define TREE_LIST_CPP
#include "../src/binear_tree.cpp"
#endif
