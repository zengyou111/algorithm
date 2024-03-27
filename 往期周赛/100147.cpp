//
// Created by zengyou on 2023/12/9.
//
#include "bits/stdc++.h"
using namespace std;
int maxSubarrayLength(vector<int>& nums, int k) {
    if(k>=nums.size())return nums.size();
    int n=nums.size();
    int left=0,right=0;
    int res=0;
    unordered_map<int,int>m;
    while(right<n){
        m[nums[right]]++;
        if(m[nums[right]]==k){
            res=max(res,right-left+1);
        }else if(m[nums[right]]>k){
            if(nums[left]==nums[right]){
                m[nums[left]]--;
            }else {
                while(nums[left]!=nums[right]){
                    m[nums[left]]--;
                    if(!m[nums[left]]){
                        m.erase(nums[left]);
                    }
                    left++;
                }
            }
            left++;
        }
        res=max(res,right-left+1);
        right++;
    }
    return res;
}
int main(){
    vector<int>tmp={1,2,2,1,3};
    cout<< maxSubarrayLength(tmp,1);
    return 0;
}
