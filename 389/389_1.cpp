//
// Created by zengyou on 2024/3/17.
//
#include "bits/stdc++.h"
using namespace std;
bool isSubstringPresent(string s) {
    set<string>se;
    int n=s.size();
    for(int i=0;i<n-1;i++){
        se.insert(s.substr(i,2));
    }
    reverse(s.begin(),s.end());
    for(int i=0;i<n-1;i++){
        if(se.count(s.substr(i,2))){}
        return true;
    }
    return false;
}
int main(){
    isSubstringPresent("abcd");
    return 0;
}

