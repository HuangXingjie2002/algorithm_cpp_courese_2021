#pragma once

#include <iostream>


class String_methods {
public:
    static int *find_next(std::string str) {
        unsigned long long length = str.length();
        int *next = new int[length]{0};
        // 获取字符串长度与创建next数组

        int index = 0;
        int m = -1;
        next[0] = -1;
        while (index < str.length() - 1) {
            if (m == -1 || str[index] == str[m]) {
                index++;
                m++;
                next[index] = m;
                // m 可以理解为上一层的next值，可以借助此变量直接推理下一层的next数组
            } else {
                m = next[m];
            }
        }
        return next;
    }

    static int kmp(const std::string &templateStr, const std::string &value) {
        int *next = find_next(value);
        int index = 0;
        for (int i = 0; i < templateStr.length() - value.length() + 1; i++) {
            if (value[index] != templateStr[i] && index == 0) {
                continue;
            } else if (value[index] != templateStr[i]) {
                index = next[index];
            } else {
                index ++;
            }
            if (index == value.length() - 1)
            {
                return true;
            }
        }
        return false;
    }
};


#ifndef STRING_CPP
#define STRING_CPP
#include "../src/string_.cpp"
#endif
