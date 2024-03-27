//
// Created by zengyou on 2023/12/17.
//
#include"bits/stdc++.h"
using namespace  std;
vector<vector<int>> divideArray(vector<int>& nums, int k) {
    int n=nums.size();
    sort(nums.begin(),nums.end());
    vector<vector<int>>res;
    for(int i=0;i<n;i+=3){
        if(nums[i+2]-nums[i]>k)return {};
        vector<int>it(nums.begin()+i,nums.begin()+i+3);
    }
    return res;
}
int main(){
    return 0;
}
