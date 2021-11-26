#include <iostream>
#include <cmath>

int k = 0;

int dfs(int *mess, int *price, std::string &ans, int head, int edge, int tail, int sum, int table, int hang) {
    // 不相等的时候返回false
    if (table < hang)
    {
        return sum;
    }

    int left = sum + dfs(mess, price, ans, head + 1, edge, tail, sum + price[head], table - k * mess[head], hang);

    int right = sum + dfs(mess, price, ans, head, edge - 1,  tail - 1, sum + price[edge], table - k * mess[edge], hang + mess[edge]);
    return left > right ? left : right;
}

void solution() {
    int n, m;
    std::cin >> n >> m >> k;

    int price[n];
    int mess[n];

    int table(0);
    int hang(0);

    for (int i = 0; i < n; i ++) {
        std::cin >> mess[i] >> price[i];
        if (i < m) {
            table += k * mess[i];
        } else {
            hang  += mess[i];
        }
    }

    int head(0), tail(n-1), edge(n - m - 1);

    std::string ans = "";
    int num(0), price(0);

    std::cout << dfs(mess, price, ans, head, edge, tail, 0, table, hang) << std::endl;
}


int main() {
    solution();
}