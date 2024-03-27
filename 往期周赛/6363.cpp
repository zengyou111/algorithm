//
// Created by zengyou on 2023/4/2.
//
#include "iostream"
#include "vector"
#include "unordered_map"
using namespace std;
vector<vector<int>> findMatrix(vector<int>& nums) {
    vector<vector<int>>ans;
    unordered_map<int,int>myMap;
    for(auto num:nums){
        myMap[num]++;
    }
    bool flag=false;
    while(!flag){
        flag=true;
        vector<int>cmp;
        for(auto &num:myMap){
            if(num.second!=0){
                flag=false;
                cmp.push_back(num.first);
                num.second--;
            }
        }
        if(!flag)ans.push_back(cmp);
        else return ans;
    }
    return ans;
}
int main(){
    vector<int>nums={1,3,4,1,2,3,1};
    findMatrix(nums);
    return 0;
}