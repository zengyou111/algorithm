//
// Created by zengyou on 2024/3/26.
//
#include "bits/stdc++.h"
using namespace std;

int maxSubarraySumCircular(vector<int>& nums) {
    if(nums.size()==1)return nums[0];
    int n=nums.size(),ans=0,sum= accumulate(nums.begin(),nums.end(),0);
    vector<int>f1(n,0),f2(n,0);
    f1[0]=f2[0]=nums[0];
    for(int i=1;i<n;i++){
        f1[i]=f1[i-1]>0?f1[i-1]+nums[i]:nums[i];
        f2[i]=f2[i-1]<0?f2[i-1]+nums[i]:nums[i];
    }
    int ans1=*max_element(f1.begin(),f1.end());
    sort(f2.begin(),f2.end());
    int ans2=*max_element(nums.begin(),nums.end())<0?f2[1]:f2[0];
    ans=max(ans1,sum-ans2);
    return ans;
}

int main(){
    vector<int>nums={9,-4,-7,9};
    cout<<maxSubarraySumCircular(nums);
    return 0;
}

