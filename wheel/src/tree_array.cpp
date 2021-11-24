//
// Created by mushr on 2021/11/6.
//

#include "../lib/queue_list.h"
#include "../lib/stack_list.h"

#include <iostream>

#ifndef TREE_ARRAY_CPP
#define TREE_ARRAY_CPP

#include "../lib/tree_array.h"

#endif


template<typename T>
tree_array<T>::tree_array() {
    this->data = nullptr;
    this->data = new T[31]; // 默认树的大小 深度最大为5
    if (this->data) {
        this->depth = 0; // 深度为0， 当前无结点
        this->node_number = 0; // 节点数为0
        this->capacity = 32; // 最大容积
    }
}

template<typename T>
tree_array<T>::tree_array(int capacity) {
    this->data = nullptr;
    this->data = new T[capacity - 1]; // 默认树的大小 深度最大为5
    if (this->data) {
        this->depth = 0; // 深度为0， 当前无结点
        this->node_number = 0; // 节点数为0
        this->capacity = capacity; // 最大容积
    }
}

template<typename T>
tree_array<T>::tree_array(T *data, int size) {
    // 复制比较好
    if (size <= 0) { throw "输入长度错误"; }
    else {
        this->data = nullptr;
        this->capacity = 1;
        while (this->capacity < size) {
            this->capacity *= 2;
        }
        this->data = new T[capacity];
        this->node_number = size;
        if (this->data) {
            for (int i = 0; i < size; i++) {
                this->data[i] = data[i]; // 依次赋值
            }
        }
    }
}


template<typename T>
bool tree_array<T>::find(T value) {
    // 从根节点开始搜索
    int ind = 0;
    bool flag = false;
    while (ind <= node_number) {
        if (this->data[ind] == value) {
            flag = true;
            break;
        }
        ind++;
    }
    return flag;
}


template<typename T>
void tree_array<T>::print(const std::string& methods) {
    if (methods == "clr") {
        queue_list<T> left;
        stack_list<int> stack; // 建立一个记录右侧结点索引的栈
        // 建立一个left队列
        // 记录根结点
        // 先序遍历先遍历根结点， 再遍历左和右
        // 依次把队列放出来

        int current = 0; // 初始化根节点


        while (current <= this->node_number) {
            left.enQueue(this->data[current]); // 当前值入队
            int right = 2 * current + 2; // 右侧端点索引入栈
            if ( right < this->node_number) {
                stack.push(right); // 入栈
            }
            current = 2 * current + 1; // 往左侧遍历
            if (current > this->node_number - 1 && !stack.isEmpty()) {
                current = stack.pop();
            }
        }

        /**
         * 重点在于入栈记录下右侧结点的索引，当发现current索引超过的时候，
         * 就从栈中拿一个出来赋值给current， 这样模拟了一种回溯的功能。
         * 最终遍历到超过this->node_number的时候终止，此时栈中没有右结点的记录，必然是大于this->node_number的
         */

        while (!left.isEmpty()) {
            std::cout << left.deQueue() << " ";
        }
    }
}


typedef struct treeNode {
    char value;
    int left;
    int right;
}tNode;

void first(tNode *tree, tNode *ori) {

    std::cout << tree->value;
    if (tree->left == 0 && tree->right == 0) {
        // 同为0开始返回
        return;
    }

    if (tree->left != 0) {
        first(&ori[tree->left-1], ori);
    }
    if (tree->right != 0) {
        first(&ori[tree->right-1], ori);
    }
}


void center(tNode *tree, tNode *ori) {


    if (tree->left == 0 && tree->right == 0) {
        // 同为0开始返回
        std::cout << tree->value;
        return;
    }
    if (tree->left != 0) {
        center(&ori[tree->left-1], ori);
    }
    std::cout << tree->value;
    if (tree->right != 0) {
        center(&ori[tree->right-1], ori);
    }
}

void last(tNode *tree, tNode *ori) {


    if (tree->left == 0 && tree->right == 0) {
        // 同为0开始返回
        std::cout << tree->value;
        return;
    }
    if (tree->left != 0) {
        last(&ori[tree->left-1], ori);
    }

    if (tree->right != 0) {
        last(&ori[tree->right-1], ori);
    }
    std::cout << tree->value;
}

void solve() {

}


int pow(int n) {
    int cycle = 1;
    for (int i = 0; i < n; i ++) {
        cycle *= 2;
    }
    return cycle;
}

int find(tNode *tree, tNode * ori, int value, int l, int r, int ID = 1) {

    if (tree->value == value) {
        return ID;
    }

    if (tree->left == 0 && tree->right == 0 && tree->value != value) {
        return 0;
    }

    if (tree->left != 0) {
        l = find(&ori[tree->left-1], ori, value,l, r,  ID+1);
    }

    if (tree->right != 0 && l == 0) {
        r = find(&ori[tree->right-1], ori, value, l, r, ID+2);
    }

    return l + r;
}
