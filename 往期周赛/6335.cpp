//
// Created by zengyou on 2023/3/26.
//
#include "iostream"
#include "map"
#include "vector"
#include "algorithm"
using  namespace std;
bool primeSubOperation(vector<int>& nums) {
    bool isprime=true;
    map<int,int>myMap={{2,1}};
    for(int i=3;i<=1000;i++){
        isprime=true;
        for(int j=2;j<i;j++){
            if(i%j==0)isprime=false;
        }
        if(isprime==true)myMap[i]=1;
    }
    int cmp=-1;
    for(int i=0;i<nums.size();i++){
        cmp=-1;
        for(auto isp:myMap){
            if(i==0&&isp.first<nums[i])cmp=isp.first;
            if(i>0&&nums[i]-isp.first>nums[i-1]&&nums[i]-isp.first>0)
                cmp=isp.first;
            else break;
        }
        if(cmp!=-1)nums[i]-=cmp;
        if(i<nums.size()-1&&nums[i]>=*min_element(nums.begin()+i+1,nums.end())){
            return false;
        }
    }
    return true;
}
int main(){
    vector<int>nums={998,2};
    primeSubOperation(nums);
    return 0;
}
