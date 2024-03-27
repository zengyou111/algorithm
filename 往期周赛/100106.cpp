#include "vector"
#include "algorithm"
#include "string"
#include "unordered_map"
using  namespace std;
//
// Created by zengyou on 2023/10/22.
//

int minimumSum(vector<int>& nums) {
    vector<int>left_min(nums.begin(),nums.end());
    vector<int>right_min(nums.begin(),nums.end());
    int tmp=nums[0];
    for(int i=1;i<nums.size();i++){
        if(nums[i]<tmp)tmp=nums[i];
        left_min[i]=tmp;
    }
    tmp=nums[nums.size()-1];
    for(int i=nums.size()-2;i>=0;i--){
        if(nums[i]<tmp)tmp=nums[i];
        right_min[i]=tmp;
    }
    int res=-1;
    for(int i=1;i<nums.size()-1;i++){
        if(nums[i]>left_min[i]&&nums[i]>right_min[i]){
            res=min(res,nums[i]+left_min[i]+right_min[i]);
        }
    }
    return res;
}
int main(){
    vector<int>nums={8,6,1,5,3};
    minimumSum(nums);
    return  0;
}
