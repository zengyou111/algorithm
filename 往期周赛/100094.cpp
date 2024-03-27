#include "vector"
#include "algorithm"
#include "string"
#include "unordered_map"
#include "set"
using  namespace std;

int sumCounts(vector<int>& nums) {
    long long res=0;
    set<int>myset;
    for(int left=0;left<nums.size();left++){
        for(int right=left;right<nums.size();right++){
            myset.emplace(nums[right]);
            res+=((myset.size()*myset.size())%((long long )1e9+7));
        }
        myset.clear();
    }
    return res;
}

//
// Created by zengyou on 2023/10/28.
//
int main(){
    return 0;
}
