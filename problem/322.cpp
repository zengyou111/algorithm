//
// Created by zengyou on 2024/3/23.
//
#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;
int coinChange(vector<int>& coins, int amount) {
    vector<int>dp(amount+1,INT_MAX/2);
    dp[0]=0;
    for(int i=1;i<=amount;i++){
        for(auto coin:coins){
            if(i>=coin){
                dp[i]= min(dp[i],dp[i-coin]+1);
            }
        }
    }
    return dp[amount]==INT_MAX/2?-1:dp[amount];
}
int main(){
    vector<int>coins={1, 2, 5};
    cout<<coinChange(coins,11);
    return 0;
}


