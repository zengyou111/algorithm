//
// Created by zengyou on 2023/8/20.
//
#include <numeric>
#include "map"
#include "vector"
#include "algorithm"
#include "string"
using namespace std;

bool search(vector<int>&nums,int left,int right,int target){
    int mid=(left+right)/2;
    while(left<=right){
        if(target<nums[mid])right=mid-1;
        else if(target>nums[mid])left=mid+1;
        else return true;
        mid=(left+right)/2;
    }
    return false;
}
int minimumSum(int n, int k) {
    int cnt=0,i=1;
    vector<int>nums;
    while(cnt<6){
        if(!search(nums,0,nums.size()-1,k-i)){
            cnt++;
            nums.push_back(i);
        }
        i++;
    }
    return accumulate(nums.begin(),nums.end(),0);
}
int main(){
    minimumSum(5,4);
    return 0;
}


