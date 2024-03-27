//
// Created by zengyou on 2024/3/23.
//
#include "bits/stdc++.h"
using namespace std;
int combinationSum4(vector<int>& nums, int target) {
    vector<int>dp(target+1,0);
    for(int i=1;i<=target;i++){
        for(auto num:nums){
            if(i>=num)
            dp[i]+=dp[i-num];
        }
    }
    return dp[target];
}
int main(){
    return 0;
}
