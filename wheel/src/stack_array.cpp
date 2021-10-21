#include <iostream>
#ifndef STACK_ARRAY_CPP
#define STACK_ARRAY_CPP
#include "../lib/stack_array.h"
#endif


template<typename T>
stack_array<T>::stack_array(int size)
{
    this->top = -1; // 头地址索引置为-1， 表示当前没有元素
    this->size = size;
    this->array = new T[size]();
    if (!array) 
    {
        std::cout << "分配内存失败!" << "创建大小为" << size * sizeof(T) << "的字节的空间" << std::endl;
    }
}

template<typename T>
bool stack_array<T>::isEmpty()
{
    return this->top == -1;
}

template<typename T>
T stack_array<T>::isFull()
{
    return this->top == size-1;
}

template<typename T>
T stack_array<T>::getTop()
{
    return this->array[this->top];
}

template<typename T>
T stack_array<T>::pop()
{
    T tamp = this->getTop();
    this->top --;
    return tamp;
}

template<typename T>
bool stack_array<T>::push(T e)
{
    if (!this->isFull())
    {
        this->array[++this->top] = e;
        return true;
    }
    else
    {
        std::cout << "栈已满，无法添加" << std::endl;
        return false;
    }
}
