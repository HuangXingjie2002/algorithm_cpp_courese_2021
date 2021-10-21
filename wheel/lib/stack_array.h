#pragma once
#include <iostream>

template<typename T>
class stack_array
{
    private: 
        T top;
        T size;
        T *array;
    
    public:
        stack_array(int size = 30);
        bool push(T e);
        T pop();
        T getTop(); // 获得栈顶元素
        bool isEmpty();
        T isFull();
};

#ifndef STACK_ARRAY_CPP
#define STACK_ARRAY_CPP
    #include "../src/stack_array.cpp"
#endif