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
    this->sorted = false;
    this->ascending = true;
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
T List<T>::remove(node<T> &p) {
    node<T> *oldPtr = &p;
    node<T> *ptr= &p;
    T data = oldPtr->data;
    ptr->pred->succ = ptr->succ;
    ptr->succ->pred = ptr->pred;
    delete oldPtr;
    _size--;
    return data;
}

template<typename T>
node<T>& List<T>::firstNode() {
    return *(header->succ);
}

template<typename T>
node<T> List<T>::lastNode() {
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
    while (trailer != (head = head->succ)) {
        visit(head->data);
    }
}


template <typename T>
int List<T>::uniquify() {
    if (_size < 2) return 0;

    int oldSize = _size;

    node<T> *p = firstNode();
    node<T> *q;
    while (trailer != ( q = p->succ)) {
        if (p->data != q->data) {
            p = q;
        } else {
            remove(q);
        }
        /**
         * if q == p, then remove q, and q = p->next
         * 1. AAABBBCCCCC
         * 2. AABBBCCCCC
         * 3. ABBBCCCCC
         * 4. ABBCCCCC
         * 5. ABCCCCC
         * 6. ABCCCC
         * 7. ABCCC
         * 8. ABCC
         * 9. ABC
         * 10. break;
         */
    }
    return oldSize - _size;
}

template<typename T>
node<T>& List<T>::search(const T &e, int n, node<T> *p, bool ascend) {
    /**
     * true pred!!!!!
     * do not include e node;
     */
    while ( 0 < n -- ) {
        if (ascend) {
            if (((p = p->pred)->data) <= e) break;
        } else {
            if (((p = p->pred)->data) >= e) break;
        }
    }
    return *p;
}



template<typename T>
node<T>& List<T>::selectMax(node<T> &p, int n) {
    // 从当前节点的后n个节点中查找一个最大的节点并返回
    node<T> *ans = (&p)->succ;
    node<T> *iter = (&p)->succ;
    while (n --) {
        if (ans->data <= iter->data) {
            ans = iter;
        }
        iter = iter->succ; // iteration
    }
    return *ans; // return reference of max node
}

template<typename T>
List<T>::List(std::initializer_list<T> li) : List() {
    auto iter = li.begin();
    while (iter != li.end()) {
        insertAsLast(*iter);
        iter ++;
    }
}



template<typename T>
void List<T>::sort(bool ascend) {
//    selectSort(*(header->succ), _size, ascend);
    insertSort(*(header->succ), _size, ascend);
    this->sorted = true;
    ascending = ascend;
}

template<typename T>
void List<T>::sortedInsert(T data) {
    if (this->sorted) {
        if (ascending) {
            node<T> *ptr = header;

            while ((ptr = ptr->succ)->data <= data);

            insertBefore(ptr, data);
        } else {
            node<T> *ptr = header;

            while ((ptr = ptr->succ)->data >= data);

            insertBefore(ptr, data);
        }
    } else {
        insertAsFirst(data);
    }
}

template<typename T>
void List<T>::selectSort(node<T> &begin, int n, bool ascend) {
    /**
     * begin from n
     */
    node<T> *head = (&begin)->pred;
    node<T> *tail = &begin;

    for (int i = 0; i < n; i++) {
        tail = tail->succ;
    }
    if (ascend) {
        while (1 < n) {
            /**
             * @file 获取最大值的地址，并且通过remove删除元素，把值赋值回来，通过insertBefore 创建一个新的节点插入。
             */
            insertBefore(tail, remove(selectMax(*head, n)));
            tail = tail->pred;
            n --;
        }
    } else {
        // in another way, we can begin form head
        while (1 < n) {
            insertAfter(head, remove(selectMax(*head, n)));
            head = head->succ;
            n --;
        }
        // it will become a reverse list compare with ascending sort form list
    }
}

template<typename T>
void List<T>::insertSort(node<T> &begin, int n, bool ascend) {
    /**
     * search for node<T> *ptr position;
     */

    node<T> *povit = (&begin);
    int N = n;
    node<T> *head = firstNode().pred;
    while (n -- > 0) {
        node<T> *p = &search(povit->data,  N - n, povit, ascend);
        insertAfter(p, remove(*povit));
        povit = povit->succ;
    }
}
