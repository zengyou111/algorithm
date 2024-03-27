//
// Created by zengyou on 2024/3/21.
//
#include "bits/stdc++.h"
using namespace std;

int lengthOfLongestSubsequence(vector<int>& nums, int target) {
    int m=nums.size(),res=0;
    vector<vector< pair<int,int> >>dp(m+1,vector<pair<int,int>>(target+1,{0,0}));
    for(int i=1;i<=m;i++){
        for(int j=1;j<=target;j++){
            dp[i][j].first=dp[i-1][j].first;
            dp[i][j].second=dp[i-1][j].second;
            if(j>=nums[i-1]){
                int tmp=dp[i-1][j-nums[i-1]].first+nums[i-1];
                if(tmp>dp[i][j].first){
                    dp[i][j].first=tmp;
                    dp[i][j].second=dp[i-1][j-nums[i-1]].second+1;
                }else if(tmp==dp[i][j].first){
                    dp[i][j].second=max(dp[i][j].second,dp[i-1][j-nums[i-1]].second+1);
                }
                if(dp[i][j].first==target){
                    res=max(res,dp[i][j].second);
                }
            }
        }
    }
    return res>0?res:-1;
}
int main(){
    vector<int>nums={2,1,8,4,7,2,10,1};
    cout<<lengthOfLongestSubsequence(nums,22);
    return 0;
}

