//
// Created by zengyou on 2024/3/27.
//
#include "bits/stdc++.h"
using namespace std;
int videoStitching(vector<vector<int>>& clips, int time) {
    vector<int>dp(time+1,INT_MAX/2);
    int r=0;
    for(auto clip:clips){
        if(clip[0]==0)r=max(r,clip[1]);
    }
    for(int i=0;i<=r;i++)dp[r]=1;
    for(int i=r+1;i<=time;i++){
        for(int j=i;j>=0;--j){
            for(auto clip:clips){
                if(clip[0]<=j&&clip[1]>=i){
                    dp[i]=min(dp[j]+1,dp[i]);
                }
            }
        }
        if(dp[i]==INT_MAX/2)return -1;
    }
    return dp[time];
}
int main(){
    return 0;
}

