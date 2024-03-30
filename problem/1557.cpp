//
// Created by zengyou on 2024/3/29.
//
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    static vector<int> findSmallestSetOfVertices(int n, vector<vector<int>> edges) {
        vector<int>cnt(n),res;
        for(auto e:edges){
            cnt[ e[1] ]++;
        }
        for(int i=0;i<n;i++){
            if(!cnt[i]){
                res.emplace_back(i);
            }
        }
        return res;
    }
};
int main(){
    Solution *s=new Solution();
    s->findSmallestSetOfVertices(1,{});
    return 0;
}

