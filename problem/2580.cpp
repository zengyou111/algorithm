//
// Created by zengyou on 2024/3/27.
//
#include "bits/stdc++.h"
using namespace std;
int mod=1'000'000'007;
int countWays(vector<vector<int>>& ranges) {
    sort(ranges.begin(),ranges.end());
    int ans=1,r=-1;
    for(auto range:ranges){
        if(range[0]>r){
            ans=(ans*2)%mod;
        }
        r=max(r,range[1]);
    }
    return ans;
}
int main(){
    return 0;
}

