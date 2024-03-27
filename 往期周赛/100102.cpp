//
// Created by zengyou on 2023/10/29.
//
#include "vector"
#include "algorithm"
#include "string"
#include "math.h"
#include "unordered_map"
#include "set"
using  namespace std;

long long minSum(vector<int>& nums1, vector<int>& nums2) {
    long long res=0,sum1=0,sum2=0;
    int cnt1= count(nums1.begin(),nums1.end(),0);
    int cnt2= count(nums2.begin(),nums2.end(),0);
    for(auto &num:nums1)sum1+=num;
    for(auto &num:nums2)sum2+num;
    if(sum1+cnt1<sum2+cnt2){
        if(!cnt1)return -1;
        else return sum2+cnt2;
    }else if (sum1+cnt1==sum2+cnt2){
        return sum1+cnt1;
    }else if (sum1+cnt1>sum2+cnt2) {
        if(!cnt2)return -1;
        return sum1+cnt1;
    }
    return -1;
}
int main(){
    vector<int>nums1={3,2,0,1,0};
    vector<int>nums2={6,5,0};
    return minSum(nums1,nums2);
}
