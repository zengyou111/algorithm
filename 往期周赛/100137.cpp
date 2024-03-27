//
// Created by zengyou on 2023/12/10.
//
#include "bits/stdc++.h"
using namespace std;

long long countSubarrays(vector<int>& nums, int k) {
    long long res=0;
    int n=nums.size();
    vector<int>left(n,-1),right(n,n);
    int tmp=-1,M=*max_element(nums.begin(),nums.end());
    for(int i=0;i<n;i++){
        left[i]=tmp;
        tmp=nums[i]==M?i:tmp;
    }
    tmp=n;
    for(int i=n-1;i>=0;i--){
        right[i]=tmp;
        tmp=nums[i]==M?i:tmp;
    }
    int slow=0,fast=0,cnt=0;
    while(slow<n&&nums[slow]!=M)slow++;
    fast=slow;
    while(fast<n){
        if(nums[fast]==M){
            cnt++;
        }
        if(cnt==k){
            res+=(1ll)*(n-fast)*(slow-left[slow])*(1ll);
            slow++;
            cnt--;
            while(slow<n&&nums[slow]!=M){
                slow++;
            }
            if(slow==n)return res;
        }
        fast++;
    }
    return res;
}


int main(){
    vector<int>tmp={28,5,58,91,24,91,53,9,48,85,16,70,91,91,47,91,61,4,54,61,49};
    cout<<countSubarrays(tmp,1)<<endl;
    return 0;
}
