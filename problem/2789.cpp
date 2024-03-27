//
// Created by zengyou on 2024/3/24.
//
#include "bits/stdc++.h"
using namespace std;
int numberOfWays(int n, int x) {
    vector<int>v;
    for(int i=1;;){
        int tmp= pow(i,x);
        if(tmp<=n){
            i++;
            v.emplace_back(tmp);
        }else break;
    }
    vector<int>dp(n+1,0);
    dp[0]=1;
    for(int y:v){
        for(int i=n;i>=1;--i){
            if(i>=y){
                dp[i]+=dp[i-y];
            }
        }
    }
    return dp[n];
}
int main(){
    cout<<numberOfWays(4,1);
    return 0;
}

