//
// Created by zengyou on 2024/3/26.
//
#include "bits/stdc++.h"
using namespace std;
int mod=1'000'000'007;
int kConcatenationMaxSum(vector<int>& arr, int k) {
    int m=*min_element(arr.begin(),arr.end()),n=arr.size();
    if(m>=0)return ((1l)*(accumulate(arr.begin(),arr.end(),0))*k)%mod;
    if(*max_element(arr.begin(),arr.end())<=0)return 0;
    vector<long>f1(n,0),f2(n,0);
    f1[0]=arr[0];
    f2[n-1]=arr[n-1];
    for(int i=1;i<n;i++){
        f1[i]=f1[i-1]>=0?(f1[i-1]+arr[i]):arr[i];
        f2[n-i-1]=f2[n-i]>=0?(f2[n-i]+arr[n-i-1]):arr[n-i-1];
    }
    long ans=*max_element(f1.begin(),f1.end()),sum=(1l)*(accumulate(arr.begin(),arr.end(),0));
    vector<long>tmp={ans,k>=2?f1[n-1]+(k-2)*(sum>0?sum:0)+f2[0]:0};
    ans= *max_element(tmp.begin(),tmp.end())%mod;
    return ans;
}


int main(){
//    vector<int>arr={1,-1};
//    vector<int>arr={1,-2,1};
//    vector<int>arr={-5,-2,0,0,3,9,-2,-5,4};
    vector<int>arr={-1,5,-7,2,-1,0,7,6,2,4};
    cout<<kConcatenationMaxSum(arr,5)<<endl;

//    cout<<kConcatenationMaxSum(arr,3)<<endl;
//    cout<<kConcatenationMaxSum(arr,1)<<endl;
//    cout<<kConcatenationMaxSum(arr,3)<<endl;
    return 0;
}
