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
    bool sorted;
    bool ascending;

    void selectSort(node<T> &begin, int n, bool ascending = true);
    void insertSort(node<T> &begin, int n, bool ascending = true);

public:
    List();

    List(List<T> &list);

    List(List<T> &list, int begin, int end);

    List(T *datas, int n);

    List(std::initializer_list<T> li);

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

    T remove(node<T> &p);

    node<T>& firstNode();

    node<T> lastNode();

    int deduplicate();

    template <typename VST>
    void traverse(VST &visit);

    int uniquify();

    node<T>& search(T const & e, int n, node<T> *p, bool ascend = true);

    node<T>& selectMax(node<T> &p, int n);

    void sort( bool ascend = true);

    void sortedInsert(T data);
};


#ifndef LIST_CPP
#define LIST_CPP
#include "../src/List.cpp"
#endif