//
// Created by mushr on 2021/10/22.
//


#include <iostream>

#ifndef QUEUE_LIST_CPP
#define QUEUE_LIST_CPP

#include "../lib/queue_list.h"

#endif

template<typename T>
queue_list<T>::queue_list() {
    // 初始化的时候将头尾指针指向同一个地址
    this->size = 0;
    Node<T> *init = new Node<T>;
    this->front = init;
    this->rear = init;
}

template<typename T>
bool queue_list<T>::isEmpty() {
    return this->front == this->rear;
    // 是否头尾指针相等
}

template<typename T>
bool queue_list<T>::enQueue(T e) {
    // 入队
    Node<T> *buffer = new Node<T>;
    if (buffer) {
        buffer->data = e;
        this->rear->next = buffer; // 连接
        this->rear = buffer;
        this->size ++; // 队列大小
        return true;
    } else {
        std::cout << "内存分配失败" << std::endl;
        exit(-1);
    }
}


template<typename T>
T queue_list<T>::deQueue() {
    T buffer = -1;
    if (!this->isEmpty()) {
        buffer = this->front->next->data;
        Node<T> *tamp = this->front;
        this->front = this->front->next; // 指向下一个
        this->size --; // 大小票减少
        delete tamp; // 释放掉 tamp
    } else {
        std::cout << "队列为空无法弹出" << std::endl;
    }
    return buffer;
}

template<typename T>
int queue_list<T>::getSize() {
    return this->size;
}

template<typename T>
T queue_list<T>::getFront() {
    if (!this->isEmpty()) {
        return this->front->next->data;
    } else {
        std::cout << "队列为空无法拿到数据" << std::endl;
        exit(-1);
    }
}




