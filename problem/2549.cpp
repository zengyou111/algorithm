//
// Created by zengyou on 2024/3/23.
//
#include"bits/stdc++.h"
using namespace std;
int distinctIntegers(int n) {
    vector<bool>vis(101, false);
    vis[n]= true;
    set<int>s;
    s.insert(n);
    while(true){
        int cnt=0;
        for(auto &k:s){
            for(int i=1;i<n;i++){
                if(k%i==1&&vis[i]== false){
                    s.insert(i);
                    vis[i]= true;
                    cnt++;
                }
            }
        }
        if(cnt==0)return s.size();
    }
    return -1;
}
int main(){
    cout<<distinctIntegers(3);
    return 0;
}
