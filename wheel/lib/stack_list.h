#pragma once

template <typename T>
class Node 
{
    public:
        T data;
        Node<T> * next;
 
};

template <typename T>
class stack_list
{
    private:
        Node<T> *top; /* 栈顶 */
    public:
        stack_list() 
        {
            top = NULL; // 初始化top节点为NULL
        };
        bool push(T e);
        T pop();
        T getTop(); // 获得栈顶元素
        bool isEmpty();
};


#ifndef STACK_LIST_CPP
#define STACK_LIST_CPP
    #include "../src/stack_list.cpp"
#endif