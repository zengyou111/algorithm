#include "vector"
#include "algorithm"
#include "string"
#include "unordered_map"
using  namespace std;
//
// Created by zengyou on 2023/10/22.
//
int minGroupsForValidAssignment(vector<int>& nums) {
    int res=0;
    unordered_map<int,int>myMap;
    for(auto &num:nums){
        myMap[num]++;
    }
    int m=INT_MAX;//最短组元素个数
   unordered_map<int,int>cntMap;
   vector<pair<int,int>>vec;
   for(auto &it:myMap){
        m=min(m,it.second);
        vec.push_back({it.first,it.second});
    }

//    for(auto &it:cntMap){
//        vec.push_back({it.first,it.second});
//    }
    for(int i=0;i<vec.size();i++){
        res+=(vec[i].second+m)/(m+1);
    }
//    sort(vec.begin(),vec.end());
//
//    for(int i=1;i<vec.size();i++){
//        if(vec[i].first-vec[i-1].first==1){
//            res=res==-1?vec[i].second+vec[i-1].second:min(res,vec[i].second+vec[i-1].second);
//        }
//    }
    return res;
}


int main(){
    vector<int>nums={1,1,3,3,1,1,2,2,3,1,3,2};
    minGroupsForValidAssignment(nums);
    return 0;
}

