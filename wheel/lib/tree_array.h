//
// Created by mushr on 2021/11/6.
//

#pragma once


template <typename T>
class tree_array {
protected:
    T *data;
    int capacity; // 容量， 数组初始化时候的最大长度
    int node_number; // 结点的数量
    int depth;

public:
    tree_array(); // 默认初始化树

    tree_array(int capacity); // 带有大小的初始化. 指定初始化的大小

    tree_array(T * data, int size); // c++ 不会检查下标是否越界，数组长度只能更具类来动态设定

    bool find(T value); // 在树中查找是否存在于一个值value;

    void print(const std::string& methods = "clr"); // 答应方式，默认前序打印

//    bool insert(T data); // 插入数据

    int getDepth() { return depth; };// 返回树的深度
};


















#ifndef TREE_ARRAY_CPP
#define TREE_ARRAY_CPP
#include "../src/tree_array.cpp"
#endif