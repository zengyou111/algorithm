//
// Created by zengyou on 2023/12/17.
//
#include"bits/stdc++.h"
using namespace  std;
vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
    int n=grid.size();
    vector<int>cnt(n*n+1,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cnt[grid[i][j]]++;
        }
    }
    int a=0,b=0;
    for(int i=1;i<=n*n;i++){
        if(cnt[i]==2)a=i;
        if(cnt[i]==0)b=i;
    }
    return {a,b};
}

int main(){
    return 0;
}
