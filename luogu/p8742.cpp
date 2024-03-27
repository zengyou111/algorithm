//
// Created by zengyou on 2024/3/24.
//
#include "bits/stdc++.h"
using namespace std;
using ll=long long;
ll solve(vector<int>&stones){
    int n=stones.size();
    set<ll>s;
    vector<ll>tmp;
    s.insert(stones[0]);
    for(int i=1;i<n;i++){
        tmp.assign(s.begin(),s.end());
        for(auto v:tmp){
            s.insert(abs(stones[i]-v));
            s.insert(stones[i]+v);
        }
    }
    return s.size();
}
int main(){
    int n;
    cin>>n;
    vector<int>stones(n);
    cout<<n<<endl;
    for(int i=0;i<n;i++){
        cin>>stones[i];
    }
    cout<<n<<endl;
    cout<<solve(stones);
    return 0;
}

