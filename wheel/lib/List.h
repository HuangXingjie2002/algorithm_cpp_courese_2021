//
// Created by mushr on 2021/12/7.
//

#include <iostream>

#pragma once

template<typename T>
class node {
public:
    T data;
    node<T> *pred; // 前驱
    node<T> *succ; // 后继
    explicit node(T e, node<T> *pred = nullptr, node<T> *succ = nullptr) : data(e), pred(pred), succ(succ) { ; }

    node() { ; }

    node<T> *insertAsPred(T e);

    node<T> *insertAsSucc(T e);
};


template<typename T>
class List {

protected:
    node<T> *header;
    node<T> *trailer;
    node<T> *first;
    node<T> *last;
    int _size;
public:
    List();

    List(List<T> &list);

    List(List<T> &list, int begin, int end);

    List(T *datas, int n);

    virtual ~List();

    node<T> *insertBefore(node<T> *p, T const &e);

    node<T> *insertAfter(node<T> *p, T const &e);

    node<T> *insertAsFirst(T e);

    node<T> *insertAsLast(T e);

    T &operator[](int k);

    node<T> *find(T e);

    node<T> *find(node<T> *p, int n, T target);

    bool empty();

    int size() {return _size;}

    T remove(node<T> *p);

    node<T>* firstNode();

    node<T>* lastNode();

    int deduplicate();

    template <typename VST>
    void traverse(VST &visit);
};


#ifndef LIST_CPP
#define LIST_CPP
#include "../src/List.cpp"
#endif