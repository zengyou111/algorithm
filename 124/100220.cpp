//
// Created by zengyou on 2024/2/17.
//
#include "bits/stdc++.h"
using namespace  std;

int tmp1=0,tmp2=0,tmp3=0;

int cnt(vector<int>nums,int target){
    int n=nums.size();
    vector<vector<int>>dp(n,vector<int>(n,0));
    for(int i=0;i<n-1;i++){
        if(nums[i]+nums[i+1]==target){
            dp[i][i+1]=1;
        }
    }
    for(int i=0;i<n-2;i++){
        dp[i][i+2]=(dp[i][i+1]|dp[i+1][i]);
    }
    for(int len=4;len<=n;len++){
        for(int i=0;i+len<=n;i++){
            int j=i+len-1;
            if(nums[i]+nums[i+1]==target){
                tmp1=dp[i+2][j];
            }
            if(nums[i]+nums[j-1]==target){
                tmp2=dp[i+1][j-1];
            }
            if(nums[j-1]+nums[j-2]==target){
                tmp3=dp[i][j-2];
            }
            dp[i][j]=max(tmp1,max(tmp2,tmp3))+1;
        }
    }
    return dp[0][n-1];
}


int maxOperations(vector<int>& nums) {
    int n=nums.size();
    return cnt(nums,nums[0]+nums[1]);
//    return max(cnt(nums,(nums[0]+nums[1])),
//               max(cnt(nums,(nums[0]+nums[n-1])),cnt(nums,(nums[n-1]+nums[n-2])))
//               );
}
int main(){

    vector<int>test={3,2,1,2,3,4};
    cout<<maxOperations(test);
    return 0;
}

