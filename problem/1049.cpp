//
// Created by zengyou on 2024/3/21.
//
#include "bits/stdc++.h"

using namespace std;
int lastStoneWeightII(vector<int>& stones) {
    int sum= accumulate(stones.begin(),stones.end(),0),target=sum/2;
    int m=stones.size();
    sort(stones.begin(),stones.end());
    vector<vector<int>>dp(m+1,vector<int>(target+1,0));
    for(int i=1;i<=m;i++){
        for(int j=1;j<=target;j++){
            dp[i][j]=dp[i-1][j];//不选
           if(j>=stones[i-1]){
               dp[i][j]=max(dp[i][j],dp[i-1][j-stones[i-1]]+stones[i-1]);
           }
        }
    }
    return sum-2*dp[m][target];
}
int main(){
    vector<int>stones={31,26,33,21,40};
    cout<<lastStoneWeightII(stones);
    return 0;
}

