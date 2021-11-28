//
// Created by mushr on 2021/11/6.
//

#include "utility.h"
#include <iostream>



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