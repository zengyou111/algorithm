//
// Created by zengyou on 2023/4/16.
//
#include "map"
#include "vector"
#include "algorithm"
using  namespace std;

int maxDivScore(vector<int>& nums, vector<int>& divisors) {
    vector<int>cmp(divisors.size(),0);
    int cnt=0,max=-1,index=0;
    for(int i=0;i<divisors.size();i++){
        cnt=0;
        for(int j=0;j<nums.size();j++){
            if(nums[j]%divisors[i]==0){
                cnt++;
            }
        }
        if(cnt>max){
            max=cnt;
            index=i;
        }
    }
    return divisors[index];
}


int main(){
    vector<int>nums={73,13,20,6};
    vector<int>divisors={56,75,83,26,24,53,56,61};
    maxDivScore(nums,divisors);
    return 0;
}
