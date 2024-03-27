//
// Created by zengyou on 2024/3/23.
//
#include "vector"
#include "iostream"
#include "algorithm"
using namespace std;
int findMaxForm(vector<string>& strs, int m, int n) {
    vector<vector<int>>dp(m+1,vector<int>(n+1,0));
    for(string str:strs){
        int cnt_0= count(str.begin(),str.end(),'0'),cnt_1=str.size()-cnt_0;
        for(int i=m;i>=cnt_0;--i){
            for(int j=n;j>=cnt_1;--j){
                dp[i][j]=max(dp[i][j],dp[i-cnt_0][j-cnt_1]+1);
            }
        }
    }
    return dp[m][n];
}
int main(){
    vector<string >strs={"10", "0", "1"};
    int m=1,n=1;
    cout<<findMaxForm(strs,m,n);
    return 0;
}

