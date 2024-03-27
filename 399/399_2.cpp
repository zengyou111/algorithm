//
// Created by zengyou on 2024/3/24.
//
#include "bits/stdc++.h"
using namespace std;
/*
 dp[i][0]:+1操作，M++,S++；S最大
 dp[i][1]:复制操作，S+=M，M不变，S最大

 * */
int minOperations(int k) {
    if(k<=1)return 0;
    int n=1'000'01;
    vector<int>dp(n,1);
    int M=1;
    for(int i=1;i<n;i++){
        for(int j=1;j<=i;j++){
            dp[i]=max(dp[i],(i-j+1)*(j+1));
        }
        if(dp[i]>=k){
            return i;
        }
    }
}
int main(){
    cout<<minOperations(11)<<endl;
    return 0;
}
