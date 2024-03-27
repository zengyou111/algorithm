//
// Created by zengyou on 2024/2/3.
//
#include "bits/stdc++.h"
using namespace std;
long long maximumSubarraySum(vector<int>& nums, int k) {
    long long res=-LLONG_MIN;
    int n=nums.size();
    unordered_map<int,vector<int>>m;
    vector<long long>sum(n+1,0);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+nums[i-1];
    }
    for(int i=0;i<n;i++){
        m[nums[i]].emplace_back(i);
    }
    for(int i=0;i<n;i++){
        int key=nums[i]+k;
        auto &x=m[key];
        for(int &v:x){
            res=max(res,sum[v+1]-sum[i]);
        }
    }
    return res==-LONG_LONG_MIN?0:res;
}
int main(){
    vector<int>test={-1,-2,-3,-4};
    cout<<maximumSubarraySum(test,2);
    return 0;
}


