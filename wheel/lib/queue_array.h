#pragma once
#include <iostream>

template <typename T>
class queue_array
{
private:
    int front{}; // 队头
    int rear{}; // 队尾
    int size{}; // 队列的大小
    T *array;
public:
    explicit queue_array(int size = 30);
    bool enQueue(T e);
    T deQueue(); // 出队
    T getFront(); // 获得队头元素
    bool isEmpty(); // 是否为空
    bool isFull(); // 是否满队
};

#ifndef QUEUE_ARRAY_CPP
#define QUEUE_ARRAY_CPP
    #include "../src/queue_array.cpp"
#endif
