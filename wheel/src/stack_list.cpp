#include <iostream>
#ifndef STACK_LIST_CPP
#define STACK_LIST_CPP
    #include "../lib/stack_list.h"
#endif

template <typename T>
bool stack_list<T>::isEmpty()
{
    return this->top == NULL;
}

template <typename T>
T stack_list<T>::getTop()
{
    return this->top->data;
}

template <typename T>
bool stack_list<T>::push(T e)
{
    Node<T> *tamp = new Node<T>;
    tamp->data = e;
    if (tamp)
    {
        tamp->next = this->top; // 当前节点的下一位指向top
        this->top = tamp; // top重新回到最高点
        return true;
    }
    else
    {
        std::cout << "分配失败！！" << std::endl;
        return false;
        exit(-1);
    }
}

template <typename T>
T stack_list<T>::pop()
{
    T tamp = this->getTop();
    Node<T> * buffer = this->top;
    this->top = this->top->next; // 头节点回归到下一个节点
    delete buffer; // 释放内存

    return tamp;
}



