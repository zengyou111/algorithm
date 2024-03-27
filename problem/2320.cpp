//
// Created by zengyou on 2024/3/25.
//
#include "bits/stdc++.h"
using namespace std;
int mod=1'000'000'007;
int countHousePlacements(int n) {
    if(n<=1)return (n+1)*(n+1);
    vector<int>dp(n+1,1);
    dp[0]=1,dp[1]=2;
    for(int i=2;i<n+1;++i){
        dp[i]=(dp[i-1]%mod+dp[i-2]%mod)%mod;
    }
    return (dp[n]%mod)*(dp[n]%mod)%mod;
}
int main(){
    cout<<countHousePlacements(2);
    return 0;
}


