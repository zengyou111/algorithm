//
// Created by zengyou on 2023/12/9.
//
#include "bits/stdc++.h"
using namespace std;
vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int,int>m1,m2;
    int cnt1=0,cnt2=0;
    int m=nums1.size(),n=nums2.size();
    for(int i=0;i<m;i++){
        m1[nums1[i]]++;
    }
    for(int i=0;i<n;i++){
        if(m1.count(nums2[i]))cnt2++;
        m2[nums2[i]]++;
    }
    for(int i=0;i<m;i++){
        if(m2.count(nums1[i]))cnt1++;
    }
    return {cnt1,cnt2};
}
int main(){

}
