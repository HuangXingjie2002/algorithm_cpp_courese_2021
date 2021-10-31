#include <iostream>

#ifndef __STRING_CPP
#define __STRING_CPP

#include "../lib/string_.h"

#endif

String::String() {
    this->data = (char *) "\0"; // 初始化为空字符串
    this->length = 0; // 字符串的长度为0
}

String::String(const char *str) {
    this->data = (char *) str;
    this->length = len(str);
}

const char *String::substring(int left, int right) {
    // 左闭右开
    int range = right - left;
    if (range < 0) {
        std::cout << "右侧索引大于左侧索引，错误！！" << std::endl;
        return this->data;
    }
    char *buffer = new char[range + 1];
    int tamp = left;
    int index(0);
    while (tamp++ < right) {
        buffer[index++] = this->data[tamp - 1];
    }
    buffer[range] = '\0';
    return buffer;
}

bool String::setData(const char *str) {
    if (nullptr != str) {
        this->data = (char *) str;
        return true;
    } else {
        return false;
    }
}

String &String::Union(const char *str) {
    int size = this->length + len(str);
    const char *tamp = this->data;
    char *buffer = new char[size + 1];
    for (int i = 0; i < this->length; i++) {
        buffer[i] = this->data[i];
    }
    for (int j = 0; j < size - this->length; j++) {
        buffer[j + this->length] = str[j];
    }
    buffer[size] = '\0';
    this->data = buffer;
    delete tamp;
    tamp = nullptr;

    this->length = size;

    return *this;
}


bool String::replace(const int index, const char c) {
    if (index >= 0 && index < this->length) {
        char *buffer = new char[this->length];
        int cycle(-1);
        int ind(0);
        while (cycle++ < this->length) {
            if (cycle == index - 1) {
                buffer[ind++] = c;
                continue;
            }
            buffer[ind++] = this->data[cycle];
        }

        buffer[ind] == '\0';
        this->data = buffer;
        this->length = ind + 1;


        return true;
    } else {
        return false;
    }
}

bool String::replace(const int index, const int length, const char *const substr) {
    if (index + length > this->length) {
        return false;
    } else {
        char *bufferLeft = (char *) this->substring(0, index);
        char *right = (char *) this->substring(index + length, this->length);
        this->data = bufferLeft;
        this->length = index;
        this->Union(substr).Union(right); // 链式存储起来
        return true;
    }
}

int String::isSubstr(const char *str) {
    int *next = String_methods::find_next(str);
    int i(0), j(0);
    int strLength = String::len(str);
    while (j != strLength && i != this->length) {
        if (this->data[i] != str[j]) {
            if (next[j] == -1) {
                j = 0;
            } else {
                j = next[j];
            }
        } else {

            j++;
        }
        i++;
    }
    if (j == strLength) {
        return i - strLength;
    } else {
        return -1;
    }
}

bool String::replace(const String &surSubstr, const String &newStr) {
    int index = this->isSubstr(surSubstr.data);
    if (index == -1) {
        return false;
    } else {
        this->replace(index, surSubstr.length, newStr.data);
        return true;
    }
}

bool String::remove(const char ch) {
    int cycle(-1);
    int index(0);
    char *buffer = new char[this->length];
    while (cycle++ < this->length) {
        if (this->data[cycle] == ch) {
            continue;
        } else {
            buffer[index++] = this->data[cycle];
        }
    }
    buffer[index] = '\0';
    this->data = buffer;
    this->length = index;
    return true;
}


bool String::remove(const int index) {
    if (index < 0 || index > this->length) {
        return false;
    }
    return this->replace(index, 1, "");
}

bool String::remove(const int index, const int count) {
    if (index < 0 || index + count > this->length) {
        return false;
    }
    return this->replace(index, count, "");
}

bool String::remove(const char *substr) {
    int ind = this->isSubstr(substr);
    int subStrLen = len(substr);
    if (ind == -1) {
        return false;
    } else {
        return this->replace(ind, subStrLen, "");
    }
}



