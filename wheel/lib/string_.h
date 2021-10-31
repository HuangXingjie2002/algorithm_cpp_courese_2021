#pragma once

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
                index++;
            }
            if (index == value.length() - 1) {
                return true;
            }
        }
        return false;
    }
};

/**
bool  replace(const int index,  const char c);         //
bool  replace(const int index, const int length,  const char * const substr);    //用字符串 substr 替换从index开始的length个字符
bool replace(const string &surSubstr, const string &newStr) //用newStr 替换子串surSubstr
bool remove(const char ch);    //删除字符串中的所有字符ch，
bool remove(const int index);  //删除指定位置的字符
bool remove(const int index, const int count);   //删除指定位置的开始指定数量的字符。
bool remove(const char *substr);    //查找并删除当前字符串中的子串;
 */


class String {
private:
    char *data;
    int length;


public:

    static int len(const char *str) {
        int count = 0;
        while (*(str++) != '\0')
        {
            count ++;
        }
        return count;
    }

    // 初始化一个string
    String();

    String(const char *str);

    // 无参构造器
    bool setData(const char *str);

    // 设置字符串
    const char *substring(int left, int right);

    // 从left 到 right 的子串
    String &Union(const char *str);

    int isSubstr(const char * str);

    char * getData() {
        return this->data;
    }

    // 拼接当前字符串和str字符串
    bool replace(const int index, const char c);         //
    bool replace(const int index, const int length, const char *const substr);    //用字符串 substr 替换从index开始的length个字符
    bool replace(const String &surSubstr, const String &newStr); //用newStr 替换子串surSubstr
    bool remove(const char ch);    //删除字符串中的所有字符ch，
    bool remove(const int index);  //删除指定位置的字符
    bool remove(const int index, const int count);   //删除指定位置的开始指定数量的字符。
    bool remove(const char *substr);    //查找并删除当前字符串中的子串;
};

#ifndef __STRING_CPP
#define __STRING_CPP
#include "../src/string_.cpp"
#endif