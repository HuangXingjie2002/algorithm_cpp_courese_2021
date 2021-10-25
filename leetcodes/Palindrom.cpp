//
// Created by mushr on 2021/10/25.
//
#include <iostream>
#include <stack>



/**
 *
 * @param str 传入的字符串
 * @return 返回是否是回文数
 */
bool isPalindrom(std::string str)
{
    int length = str.length();
    for (int i = 0; i < length / 2; i ++)
    {
        if (str[i] != str[length - 1 - i])
        {
            return false;
        }
    }

    /*
     *
     * 或者直接
     * string buffer = a;
     * reverse(a.begin(), a.end())
     * return buffer == a;
     * 如果翻转之后仍然是相同的便是回文
     * */
    return true;
}


/**
 *
 * @param num 数字
 * @param p 向多少转换
 * @return 返回转后后进制的字符串
 */
std::string transform(int num, int p)
{
    std::stack<int> stack;
    while (num > 0)
    {
        stack.push(num%p);
        num /= p;
    }
    std::string ans = "";
    while (!stack.empty())
    {
        ans += std::to_string(stack.top());
        stack.pop();
    }
    return ans;
}