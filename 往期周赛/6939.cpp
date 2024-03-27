//
// Created by zengyou on 2023/8/13.
//
#include "map"
#include "vector"
#include "algorithm"
#include "string"

using namespace std;
int maxNum(int num){
    int res=0,cmp=0;
    do{
        cmp=num%10;
        res=cmp>res?cmp:res;
        num/=10;
    }while(num);
    return res;
}
int maxSum(vector<int>& nums) {
    vector<vector<int>>res(10,vector<int>(0));
    int cmp=0;
    for(int i=0;i<nums.size();i++){
        cmp=maxNum(nums[i]);
        res[cmp].push_back(nums[i]);
    }
    int flag=0;
    for(int i=0;i<9;i++){
        if(res[i].size()>1){
            flag=1;
            break;
        }
    }
    if(!flag)return -1;
    int result=0;
    for(int i=0;i<9;i++){
        sort(res[i].begin(),res[i].end(),[&](const int&a,const int &b)->bool{
            return a>b;
        });
        if(res[i].size()>1)result=max(result,res[i][0]+res[i][1]);
    }
    return result;

}

int main(){
    vector<int>nums={96,46,85,19,29};
    return maxSum(nums);
}

