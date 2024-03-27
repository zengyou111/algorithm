//
// Created by zengyou on 2023/11/12.
//
#include<bits/stdc++.h>
using namespace  std;
int minOperations(vector<int>& nums1, vector<int>& nums2) {
    vector<int>nums3,nums4;
    nums3.assign(nums1.begin(),nums1.end());
    nums4.assign(nums2.begin(),nums2.end());
    int res1=0,res2=1,len=nums2.size(),i=nums2.size()-1,tmp=0;

    auto fun1=[&](){
        tmp=nums1[i];
        nums1[i]=nums2[i];
        nums2[i]=tmp;
    };

    auto fun2=[&](){
        tmp=nums3[i];
        nums3[i]=nums4[i];
        nums4[i]=tmp;
    };
    //第二种情况，替换数组的最后一位
    fun2();
    for(i=0;i<len;i++){
        if(nums1[i]>nums1[len-1]||nums2[i]>nums2[len-1]){
            fun1();
            res1++;
        }else{
            continue;
        }
        if(nums1[i]>nums1[len-1]||nums2[i]>nums2[len-1]){
            res1=INT_MAX;
            break;
        }
    }
    for(i=0;i<len-1;i++){
        if(nums3[i]>nums3[len-1]||nums4[i]>nums4[len-1]){
            fun2();
            res2++;
        }else{
            continue;
        }
        if(nums3[i]>nums3[len-1]||nums4[i]>nums4[len-1]){
            res2=INT_MAX;
            break;
        }
    }
    int res=min(res1,res2);
    return res==INT_MAX?-1:res;
}
int main(){
    vector<int>nums1={2,3,4,5,9};
    vector<int>nums2={8,8,4,4,4};
    minOperations(nums1,nums2);
    return 0;
}

