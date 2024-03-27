//
// Created by zengyou on 2024/3/24.
//
#include "bits/stdc++.h"
using namespace std;
int maximumLengthSubstring(string s) {
    int n=s.size(),res=0;
    for(int i=0;i<n;i++){
        vector<int>v(26,0);
        for(int j=i;;j++){
            if(j==n){
                res=max(res,j-i);
                break;
            }
            v[s[j]-'a']++;
            if(v[s[j]-'a']>2){
                res=max(res,j-i);
                break;
            }
        }
    }
    return res;
}
int main(){
    cout<<maximumLengthSubstring("bcbbbcba")<<endl;
    cout<<maximumLengthSubstring("aaaa")<<endl;
    return 0;
}

