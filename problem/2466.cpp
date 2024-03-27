//
// Created by zengyou on 2024/3/25.
//
#include"bits/stdc++.h"
using namespace std;
int mod=1'000'000'007;
int countGoodStrings(int low, int high, int zero, int one) {
    int l=min(zero,one);
    vector<int>dp(high+1);
    dp[zero]+=1,dp[one]+=1;
    for(int i=l+1;i<=high;i++){
        dp[i]=(dp[i]+((i>=zero?dp[i-zero]:0)+(i>=one?dp[i-one]:0) )%mod)%mod;
    }
    int res=0;
    for(int i=low;i<=high;i++){
        res=(res+dp[i])%mod;
    }
    return res;
}
int main(){
//    cout<<countGoodStrings(3,3,1,1)<<endl;
    cout<<countGoodStrings(5,5,5,2)<<endl;
    return 0;
}
