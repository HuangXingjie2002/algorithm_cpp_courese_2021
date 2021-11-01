//
// Created by mushr on 2021/11/1.
//

#include <iostream>

#ifndef LINKLIST_CPP
#define  LINKLIST_CPP

#include "../lib/linklist.h"

#endif


template<typename T>
linklist<T>::linklist() {
    this->head = new Node<T>;
    this->rear = new Node<T>;

    if (!(this->head && this->rear)) {
        std::cout << "初始化失败" << std::endl;
    } else {
        this->rear->next = this->head;
        this->head->pre = this->rear;

        this->head->next = nullptr;
        this->rear->pre = nullptr;

        this->isSort = false; // 假设不是有序的
    }

    this->size = 0;
    // 初始化一个链表
}


template<typename T>
bool linklist<T>::append(T value) {
    bool flag = false;
    Node<T> *buffer = new Node<T>;
    if (buffer) {
        flag = true;
        buffer->value = value;
        // 赋值

        this->head->pre->next = buffer;
        buffer->pre = this->head->pre;
        // 队尾
        buffer->next = this->head;
        this->head->pre = buffer;
        // 指向队头
    } else {
        flag = false;
        throw "分配内存失败";
    }
    return flag;
}


template<typename T>
void linklist<T>::print() {
    Node<T> *tamp = this->rear->next;

    while (tamp->next->next != nullptr) {
        std::cout << tamp->value << " ";
        tamp = tamp->next;
    }

    std::cout << tamp->value << std::endl;
}

template<typename T>
void linklist<T>::merge(linklist<T> &list) {
    Node<T> * buffer = list->rear->next;
    while (buffer != nullptr) {
        Node<T> * tamp = this->rear->next;
        while (tamp->value < buffer->value && buffer->next != list->head) {
            buffer = buffer->next;
        }

        auto *t = new Node<T>;
        t->value = buffer->value;

        linklist<T>::insert(tamp->pre, t, tamp);
        tamp = t;
    }
}


template<typename T>
static void insert(Node<T> *left, Node<T> *mid, Node<T> *right) {
    left->next = mid;
    mid->next = right;

    right->pre = mid;
    mid->pre = left;
}