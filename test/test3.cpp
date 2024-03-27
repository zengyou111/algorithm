//
// Created by zengyou on 2023/12/2.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 状态数组
vector<vector<int>> dp;
// 备忘录，用于记录中间结果
vector<vector<int>> memo;

// 计算最长公共子序列的长度
int longestCommonSubsequence(const vector<char>& X, const vector<char>& Y, int m, int n) {
    if (m == 0 || n == 0) {
        return 0;
    }

    if (memo[m][n] != -1) {
        return memo[m][n];
    }

    if (X[m - 1] == Y[n - 1]) {
        memo[m][n] = 1 + longestCommonSubsequence(X, Y, m - 1, n - 1);
    } else {
        memo[m][n] = max(longestCommonSubsequence(X, Y, m - 1, n), longestCommonSubsequence(X, Y, m, n - 1));
    }

    return memo[m][n];
}

// 构造备忘录
void buildMemo(const vector<char>& X, const vector<char>& Y) {
    int m = X.size();
    int n = Y.size();

    dp.resize(m + 1, vector<int>(n + 1, -1));
    memo.resize(m + 1, vector<int>(n + 1, -1));

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
}

// 输出最长公共子序列
void printLCS(const vector<char>& X, const vector<char>& Y, int m, int n) {
    if (m == 0 || n == 0) {
        return;
    }

    if (X[m - 1] == Y[n - 1]) {
        printLCS(X, Y, m - 1, n - 1);
        cout << X[m - 1] << " ";
    } else if (dp[m - 1][n] >= dp[m][n - 1]) {
        printLCS(X, Y, m - 1, n);
    } else {
        printLCS(X, Y, m, n - 1);
    }
}

int main() {
    vector<char> X = {'a', 'b', 'c', 'b', 'd', 'b'};
    vector<char> Y = {'a', 'c', 'b', 'b'};

    int m = X.size();
    int n = Y.size();

    buildMemo(X, Y);

    cout << "Length of Longest Common Subsequence: " << dp[m][n] << endl;

    cout << "Longest Common Subsequence: ";
    printLCS(X, Y, m, n);

    return 0;
}


