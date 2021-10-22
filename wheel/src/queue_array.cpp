#include <iostream>
#ifndef QUEUE_ARRAY_CPP
#define QUEUE_ARRAY_CPP
#include "../lib/queue_array.h"
#endif


template <typename T>
queue_array<T>::queue_array(int size) : size(size)
{
    this->array = new T[size]; // 创建size大小的数组
    if (array)
    {
        this->front = -1;
        this->rear = -1;
    }
    else
    {
        std::cout << "队列创建失败" << std::endl;
        exit(-1);
    }
}

template <typename T>
bool queue_array<T>::isFull()
{
    return ((this->rear+1) % this->size) == this->front;
    // 只有当出队列的时候，才会可以判断队列是否是满队列，否则会一直覆盖。
}

template <typename T>
bool queue_array<T>::enQueue(T data)
{
    if (!this->isFull())
    {
        this->rear = (this->rear + 1) % this->size;
        this->array[this->rear] = data; // 赋值
        return true;
    }
    else
    {
        std::cout << "队列已满，请出队列后再继续添加" << std::endl;
        return false;
    }
}


template <typename T>
T queue_array<T>::deQueue()
{
    this->front = (this->front + 1) % this->size;
    return this->array[this->front]; // 返回front下一个元素， 也就是说当前的this->front 不算元素，已经被返回了
}

template <typename T>
T queue_array<T>::getFront()
{
    return this->array[this->front + 1];
}


template <typename T>
bool queue_array<T>::isEmpty()
{
    return this->front == this->rear;
}