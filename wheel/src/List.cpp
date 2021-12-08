//
// Created by mushr on 2021/12/7.
//

#include <iostream>

#ifndef LIST_CPP
#define LIST_CPP

#include "../lib/List.h"

#endif


template<typename T>
node<T> *node<T>::insertAsPred(T e) {
    auto *newNode = new node(e, this->pred, this);
    this->pred->succ = newNode;
    this->pred = newNode;
    return newNode;
}

template<typename T>
node<T> *node<T>::insertAsSucc(T e) {
    auto *newNode = new node(e, this, this->succ);
    this->succ->pred = newNode;
    this->succ = newNode;
    return newNode;
}

template<typename T>
List<T>::List() {
    this->header = new node<T>();
    this->trailer = new node<T>();
    this->header->pred = nullptr;
    this->header->succ = this->trailer;
    this->trailer->pred = this->header;
    this->trailer->succ = nullptr;
    _size = 0; // init size as 0
}

template<typename T>
node<T> *List<T>::insertBefore(node<T> *p, const T &e) {
    _size++;
    return p->insertAsPred(e);
}

template<typename T>
node<T> *List<T>::insertAfter(node<T> *p, const T &e) {
    _size++;
    return p->insertAsSucc(e);
}

template<typename T>
node<T> *List<T>::insertAsLast(T e) {
    _size++;
    return this->trailer->insertAsPred(e);
}

template<typename T>
node<T> *List<T>::insertAsFirst(T e) {
    _size++;
    return this->header->insertAsSucc(e);
}

template<typename T>
List<T>::List(List &list) : List() {
    node<T> *ptrOri = header;
    node<T> *ptrCopy = list.header;
    while (_size < list._size) {
        ptrOri = ptrOri->insertAsSucc(ptrCopy->succ->data);
        ptrCopy = ptrCopy->succ;
        _size++;
    }
}

template<typename T>
List<T>::List(T *datas, int n) : List() {
    node<T> *ptr = header;
    while (_size < n) {
        ptr = ptr->insertAsSucc(datas[_size]);
        _size++;
    }
}

template<typename T>
T &List<T>::operator[](int k) {
    node<T> *ptr = header;
    if (k < _size / 2) {
        while (k-- >= 0) {
            ptr = ptr->succ;
        }
    } else {
        k = _size - k - 1;
        ptr = trailer;
        while (k-- >= 0) {
            ptr = ptr->pred;
        }
    }
    return ptr->data;
}

template<typename T>
node<T> *List<T>::find(T e) {
    node<T> *ptr = header;
    while (ptr->succ && (ptr = ptr->succ)->data != e);
    return ptr->succ == NULL ? NULL : ptr;
}

template<typename T>
node<T> *List<T>::find(node<T> *p, int n, T target) {
    /**
     * [p-n + 1, ..., p-1, p]
     */
    p = p->pred;
    while (n-- > 0) {
        if (p->data == target) return p;
        else p = p->pred;
    }
    return nullptr;
}

template<typename T>
List<T>::List(List<T> &list, int begin, int end) : List() {
    node<T> *ptrOri = header;
    node<T> *ptrCopy = list.header;
    int length = end - begin;
    while (begin-- > 0) {
        ptrCopy = ptrCopy->succ;
    }
    while (_size < length) {
        ptrOri = ptrOri->insertAsSucc(ptrCopy->succ->data);
        ptrCopy = ptrCopy->succ;
        _size++;
    }
}

template<typename T>
bool List<T>::empty() {
    return (header->succ == trailer) & (trailer->pred == header);
}

template<typename T>
List<T>::~List() {
    node<T> *ptr = header->succ;

    while (ptr) {
        delete header;
        header = ptr;
        ptr = ptr->succ;
    }
    delete header;
}

template<typename T>
T List<T>::remove(node<T> *p) {
    node<T> *oldPtr = p;
    T data = oldPtr->data;
    p->pred->succ = p->succ;
    p->succ->pred = p->pred;
    delete oldPtr;
    _size--;
    return data;

}

template<typename T>
node<T> *List<T>::firstNode() {
    return header->succ;
}

template<typename T>
node<T> *List<T>::lastNode() {
    return trailer->pred;
}

template<typename T>
int List<T>::deduplicate() {
    int r(0); // r is record the true label index
    node<T> *buffer = header;
    int oldSize = _size;

    while (trailer != (buffer = buffer->succ)) {
        node<T> *tamp = find(buffer, r, buffer->data);
        tamp ? remove(tamp) : r++;
    }

    return oldSize - _size;
}

template<typename T>
template<typename VST>
void List<T>::traverse(VST &visit) {
    node<T> *head = header;
    while (trailer != (head = head -> succ)) {
        visit(head->data);
    }
}
