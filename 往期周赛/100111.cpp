#include "vector"
#include "algorithm"
#include "string"
#include "math.h"
#include "unordered_map"
#include "set"
using  namespace std;
//
// Created by zengyou on 2023/10/29.
//

int findKOr(vector<int>& nums, int k) {
    vector<int>tmp(32,0);
    int res=0;
    int cnt=0;
    for(int i=0;i<32;i++){
        cnt=0;
        for(int j=0;j<nums.size();j++){
            if(nums[j]&1)cnt++;
            nums[j]>>=1;
        }
        tmp[i]=cnt;
        if(cnt>=k)
            res+=pow(2,i);
    }
    return res;
}



int main(){
    vector<int>nums={7,12,9,8,9,15};

    return 0;
}
