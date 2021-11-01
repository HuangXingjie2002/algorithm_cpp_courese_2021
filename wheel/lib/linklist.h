//
// Created by mushr on 2021/11/1.
//

#pragma once

template <typename T>
class Node {
public:
    T value;
    Node *pre;
    Node *next;
};


template <typename T>
class linklist {
private:
    int size;
    Node<T> * head;
    Node<T> * rear;
    bool isSort;

public:
    linklist();

    bool append(T value);

//    bool find(T value);
//
//    void sort();
//
    void merge(linklist<T> &list);
//
//    void delValue(T value); // 删除链表中值 = value 的节点
    void print();


    static void insert(Node<T> *left, Node<T> *mid, Node<T> *right);
};









#ifndef LINKLIST_CPP
#define  LINKLIST_CPP
#include "../src/linklist.cpp"
#endif