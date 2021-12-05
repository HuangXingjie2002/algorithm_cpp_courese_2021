//
// Created by mushr on 2021/11/6.
//

#include "utility.h"
#include <iostream>
#include <queue>


int64_t fib(int n) {
    int f(0), g(1);
    while (0 < n --) {
        g = f + g;
        f = g - f;
    }
    return g;
}

// 递归版本的最长公共子序列
string recLCS(string A, string B) {
    if (A.length() == 0 || B.length() == 0)
        return "";
    if (A[A.length() - 1] == B[B.length() - 1])
        return recLCS(A.substr(0, A.length()-1), B.substr(0, B.length() - 1)) + A[A.length() - 1];
    else {
        string a = recLCS(A.substr(0, A.length() - 1), B);
        string b = recLCS(A, B.substr(0, B.length() - 1));
        return a.length() > b.length() ? a : b;
    }
}


//#include <vector>
//int dpLCS(string A, string B) {
//    int lengthA = A.length();
//    int lengthB = B.length();
//
//    // dp vector
//
////    vector<vector<int>> dp(lengthA + 1, vector<int>(lengthB + 1));
//    vector<int> dp(lengthB + 1);
//
//    int tamp;
//    for (int row = 1; row <= lengthA; row ++) {
//        for (int col = 1; col <= lengthB; col ++) {
//            if (A[row-1] == B[col-1] )
//                tamp = 1;
//            else
//                tamp = 0;
//            dp[col] = max(dp[col], dp[col - 1]) + tamp;
//        }
//    }
//    return dp[lengthB];
//}

#include <vector>
int dpLCS(string A, string B) {
    int lengthA = A.length();
    int lengthB = B.length();

    // dp vector

    vector<vector<int>> dp(2, vector<int>(lengthB + 1));

    int tamp;
    for (int row = 1; row <= lengthA; row ++) {
        for (int col = 1; col <= lengthB; col ++) {
            if (A[row] == B[col] )
                tamp = 1;
            else
                tamp = 0;
            dp[row%2][col] = max(dp[(row - 1)%2][col], dp[(row)%2][col - 1]) + tamp;
        }
    }
    return dp[lengthA%2][lengthB];
}

//void DFS(vector<vector<int>> &matrix, int &count, vector<int> &visit, int size, int row) {
//    if (count == size) {
//        return;
//    }
//
//    for (int i = 0; i < size; i ++) {
//        if (visit[i] != 1 && matrix[row][i] == 1) {
//            cout << i << " ";
//            visit[i] = 1;
//            count ++;
//            DFS(matrix, count, visit, size, i);
//        }
//    }
//}

void BFS(vector<vector<int>> &matrix, vector<int> &visit, int size, int row, int &count) {
    if (count == size) {
        return;
    }
    queue<int> buffer;
    for (int i = 0; i < size; i ++) {
        if (visit[i] == 0 && matrix[row][i] == 1) {
            buffer.push(i);
        }
    }

    while (!buffer.empty() && count != size) {
        int top = buffer.front();
        buffer.pop();
        std::cout << top << " ";
        visit[top] = 1;
        count ++;
        BFS(matrix, visit, size, top, count);
    }
}

int* range(int begin, int end) {
    int *array = new int[end - begin];

    for (int i = begin; i < end; i ++) {
        array[i-begin] = i;
    }
    return array;
}

template <typename T>
void Swap(T &a, T &b) {
    T buffer = a;
    a = b;
    b = buffer;
}