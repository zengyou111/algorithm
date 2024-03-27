//
// Created by zengyou on 2023/12/2.
//

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// 状态数组
vector<vector<int>> dp;
// 备忘录，用于记录中间结果
vector<vector<int>> memo;
// 标记函数，用于追踪解
vector<vector<int>> mark;

// 计算最小的乘法次数
int matrixChainOrder(const vector<int>& P, int i, int j) {
    if (i == j) {
        return 0;
    }

    if (memo[i][j] != -1) {
        return memo[i][j];
    }

    int minCost = INT_MAX;

    for (int k = i; k < j; k++) {
        int cost = matrixChainOrder(P, i, k) +
                   matrixChainOrder(P, k + 1, j) +
                   P[i - 1] * P[k] * P[j];

        if (cost < minCost) {
            minCost = cost;
            mark[i][j] = k;  // 记录分割位置
        }
    }

    memo[i][j] = minCost;
    return minCost;
}

// 构造备忘录和标记函数
void buildMemoAndMark(const vector<int>& P) {
    int n = P.size() - 1;

    dp.resize(n + 1, vector<int>(n + 1, -1));
    memo.resize(n + 1, vector<int>(n + 1, -1));
    mark.resize(n + 1, vector<int>(n + 1, -1));

    for (int i = 1; i <= n; i++) {
        dp[i][i] = 0;
        memo[i][i] = 0;
    }

    for (int len = 2; len <= n; len++) {
        for (int i = 1; i <= n - len + 1; i++) {
            int j = i + len - 1;
            dp[i][j] = matrixChainOrder(P, i, j);
        }
    }
}

// 输出最优解
void printOptimalParentheses(const vector<int>& P, int i, int j) {
    if (i == j) {
        cout << "A" << i;
    } else {
        cout << "(";
        printOptimalParentheses(P, i, mark[i][j]);
        printOptimalParentheses(P, mark[i][j] + 1, j);
        cout << ")";
    }
}

int main() {
    vector<int> P = {50, 10, 40, 30, 5, 20, 15};
    int n = P.size() - 1;

    buildMemoAndMark(P);

    cout << "Minimum number of multiplications: " << dp[1][n] << endl;

    cout << "Optimal Parentheses: ";
    printOptimalParentheses(P, 1, n);

    return 0;
}
