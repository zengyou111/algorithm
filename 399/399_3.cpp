//
// Created by zengyou on 2024/3/24.
//
#include "bits/stdc++.h"
using namespace std;
vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
    int n=freq.size();
    struct Compare {
        bool operator() (const pair<int, int>& a, const pair<int, int>& b) {
            return a.second < b.second; // 按照pair的第二个元素从小到大排序
        }
    };
    multimap<int,pair<int,int>, Compare> M;

    for(int i=0;i<n;i++){
        if(freq[i]>0){
//            M[ nums[i] ].second+=freq[i];
        }
    }
}
int main(){
    return 0;
}
