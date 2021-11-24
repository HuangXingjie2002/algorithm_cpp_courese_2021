//
// Created by mushr on 2021/11/20.
//

/**
* Description

一个有n个节点的连通图，这些节点以编号：1、2、……n进行编号，现给出节点间的连接关系。请以节点1为起点，按dfs的顺序遍历并输出该图。


Input
第一行为两整数，n和e，表示n个顶点，e条边

以下e行每行两个数，表示两个节点是联通的


Output
只有一行，为节点的dfs顺序
*/


/**
 * 1. 该如何表示该结构， 使用矩阵，然后传入指针，递归调用，并且在递归中调用修改信息 可行，每轮只需要检查是否还有1
 * 2. 邻接矩阵怎么表示? 一维数组，使用i*col + j的形式存储
 * 3. 每次递归修改什么? 当发现有1的时候开始递归，每次遇到非0，列转行进入索引，
 * 并且第一时间将原先位置修改为0，切断联系，并且输出。
 */

#include <iostream>

void dfs(int * reachMatrix, int row, int col, int nodeNum, int to, int * num, bool *flag) {
    if (reachMatrix[nodeNum * row + col] == 1) {

        if (*num == nodeNum) {
            std::cout << col + 1;
            *num += 1;
        }  else {
            std::cout << col + 1 << " ";
        }
        for (int j = 0; j < nodeNum; j ++) {
            reachMatrix[nodeNum * j + col] = 0; // 禁止其他结点到达 col
        }
    }

    for (int i = 0; i < nodeNum; i ++) {
        if (nodeNum * to + i < nodeNum*nodeNum && reachMatrix[nodeNum * to + i] == 1) {
            if (*flag == true) {
                std::cout << i << " ";
                *flag = false;
            }
            dfs(reachMatrix, to, i, nodeNum, i, num, flag);
        }
    }
}

//int main() {
//    int nodeNum, edges;
//
//    std::cin >> nodeNum >> edges;
//
//    int reachMatrix[nodeNum * nodeNum];
//
//    int i, j;
//    for (int index = 0; index < edges; index ++) {
//        std::cin >> i >> j;
//        reachMatrix[(i-1) * nodeNum + (j - 1)] = 1;
//    }
//    int a = 1;
//    int * ptr = &a;
//    bool flag = true;
//    dfs(reachMatrix, 0, 0, nodeNum, 0, ptr, &flag);
//}