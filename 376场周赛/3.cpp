//
// Created by zengyou on 2023/12/17.
//
#include"bits/stdc++.h"
using namespace  std;
bool adjust(int num){
    string s=to_string(num);
    int l=0,r=s.size()-1;
    while(l<r){
        if(s[l]!=s[r])return false;
        l++,r--;
    }
    return true;
}

int index(vector<int>&nums,int target){
    if(nums[0]>target)return 0;
    int left=1,right=nums.size()-1,mid=0;
    while(left<=right){
        mid=(left+right)/2;
        if(nums[mid]<target)left++;
        else if(nums[mid-1]>=target)right--;
        else if(nums[mid]>=target&&nums[mid-1]<target)return mid;
    }
    return -1;
}

long long minimumCost(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    int n=nums.size();
    // long long sum=accumulate(nums.begin(),nums.end(),0);
    vector<long long>SUM(n+1,0);
    for(int i=1;i<=n;i++){
        SUM[i]+=SUM[i-1]+nums[i-1];
    }
    int l=nums[0],r=nums[n-1],mid=(l+r)/2;
    l=mid,r=mid+1;
    long long sum1=LONG_LONG_MAX,sum2=LONG_LONG_MAX;
    while(l){
        long  long s=0;
        if(!adjust(l)){
            l--;
            continue;
        }else{
            if(l>nums[0]){
                int i=index(nums,l);
                s=(SUM[n]-SUM[i])-(1ll)*(n-i)*(l)*(1ll)+(1ll)*(i)*(l)*(1ll)-(SUM[i]-SUM[0]);
                sum1=min(sum1,s);
                l--;
            }else{
                s=SUM[n]-(1ll)*l*n*(1ll);
                sum1=min(sum1,s);
                l=0;
                break;
            }
        }
    }
    while(r<INT_MAX){
        long long s=0;
        if(!adjust(r)){
            r++;
            continue;
        }else{
            if(r<nums[n-1]){
                int i= index(nums,r);
                s=(SUM[n]-SUM[i])-(1ll)*(n-i)*(r)*(1ll)+(1ll)*(i)*(r)*(1ll)-(SUM[i]-SUM[0]);
                sum2=min(s,sum2);
                r++;
            }else{
                s=(1ll)*r*n*(1ll)-SUM[n];
                sum2=min(s,sum2);
                r=INT_MAX;
                break;
            }
        }
    }
    return min(sum1,sum2);
}

int main(){
    vector<int>test1={1,2,3,4,5};
    vector<int>test2={10,12,13,14,15};
    vector<int>test3={22,33,22,33,22};
    cout<<minimumCost(test1);
    return 0;
}

