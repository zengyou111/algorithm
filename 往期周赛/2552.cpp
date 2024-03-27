//
// Created by zengyou on 2023/11/10.
//
#include "iostream"
#include "vector"
#include "algorithm"
#include "string"
#include "math.h"
#include "unordered_map"
#include "set"
#include "map"
#include "queue"
using  namespace std;
int left_small[4001][4001],right_large[4001][4001];
long long countQuadruplets(vector<int>& nums) {
    long long res=0;
    //left_small[k][x]:k左边比x的数,right_large[k][x]：k右边比x大的数

    int len=nums.size();
    for(int right=len-1;right>=0;right--){
        for(int left=right-1;left>=0;left--){
            if(nums[left]<nums[right]){
                right_large[left][nums[left]]++;
            }
        }
    }
    for(int left=0;left<len;left++){
        for(int right=left+1;right<len;right++){
            if(nums[right]>nums[left]){
                left_small[right][nums[right]]++;
            }
        }
    }
    for(int j=1;j<len-2;j++){
        for(int k=j+1;k<len-1;k++){
            if(nums[k]>nums[j])continue;
            res+=(left_small[j][nums[k]])*(right_large[k][nums[j]]);
        }
    }
    return res;
}


int main(){
    vector<int>nums={1,3,2,4};
    cout<<countQuadruplets(nums);

    return 0;
}

