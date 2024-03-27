//
// Created by zengyou on 2024/3/24.
//
#include "bits/stdc++.h"
using namespace std;
int numSquares(int n) {
    vector<int>dp(n+1,INT_MAX);
    dp[0]=0;
    for(int i=1;i<=n;i++){
        for(int x=1;x*x<=i;x++){
            if(i>=x*x){
                dp[i]=min(dp[i],dp[i-x*x]+1);
            }
        }
    }
    return dp[n];
}
int main(){
    cout<<numSquares(12)<<endl;
    cout<<numSquares(13)<<endl;
    return 0;
}
