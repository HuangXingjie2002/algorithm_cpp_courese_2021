//
// Created by mushr on 2021/11/1.
//


// 链表相关的方法

#include "linklistRel.h"
#include <iostream>

typedef struct node {
    int value;
    struct node * next;
} Node;


Node * create(char end) {
    Node * head;
    Node * front = new Node;
    std::cin >> front->value;
    head = front;
    while (getchar() != end) {
        Node * buffer = new Node;
        std::cin >> buffer->value;
        head->next = buffer;
        head = head->next;
    }

    head->next = nullptr;
    return front;
}

void print(Node * linklist) {
    while (linklist->next != nullptr) {
        std::cout << linklist->value << " ";
        linklist = linklist->next;
    }

    std::cout << linklist->value << std::endl;
}


Node * merge(Node *l1, Node *l2) {
    Node * head;
    Node * front = new Node;

    head = front;
    bool flag = true;

    if (l1->value > l2 -> value) {
        front->value = l2->value;
        l2 = l2->next;
    } else {
        front->value = l1->value;
        l1 = l1->next;
    }



    while (l1 != nullptr && l2 != nullptr) {
        if (l1->value > l2 -> value) {
            Node * buffer = new Node;
            buffer->value = l2->value;
            front->next = buffer;
            front = front->next;

            l2 = l2->next;

        } else {
            Node * buffer = new Node;
            buffer->value = l1->value;
            front->next = buffer;
            front = front->next;

            l1 = l1->next;
        }
    }

    if (l1 != nullptr) {
        while (l1 != nullptr) {
            Node * buffer = new Node;
            buffer->value = l1->value;

            front->next = buffer;
            front = front->next;

            l1 = l1->next;
        }

    } else if (l2 != nullptr) {
        while (l2 != nullptr) {
            Node * buffer = new Node;
            buffer->value = l2->value;

            front->next = buffer;
            front = front->next;

            l2 = l2->next;

        }
    }

    front->next = nullptr;
    return head;
}