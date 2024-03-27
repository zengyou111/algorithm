//
// Created by zengyou on 2024/3/16.
//
#include "bits/stdc++.h"

using namespace std;
vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) {
    long long sum=0;
    int n=nums.size(),m=queries.size();
    vector<long long>res(m,0);
    for(auto &num:nums)sum+=num;
    priority_queue<pair<int,int>,vector< pair<int,int> >,greater<pair<int,int>> >q;
    set<int>s;
    for(int i=0;i<n;i++){
        q.push({nums[i],i});
    }
    for(int i=0;i<m;i++){
        int index=queries[i][0],k=queries[i][1];
        if(!s.count(index)){
            sum-=nums[index];
            s.insert(index);
        }
        while(k){
            if(q.empty()){
                break;
            }
            auto x=q.top();
            q.pop();
            if(s.count(x.second)){
                continue;
            }else{
                s.insert(x.second);
                sum-=x.first;
                --k;
            }
        }
        res[i]=sum;
    }
    return res;
}
int main(){


    vector<int>nums={1,2,2,1,2,3,1};
    vector<vector<int>>queries={{1,2},{3,3},{4,2}};
    unmarkedSumArray(nums,queries);
    return 0;
}

