//
// Created by zengyou on 2024/3/17.
//
#include "bits/stdc++.h"
using namespace std;
long long countSubstrings(string s, char c) {
    long long res=0;
    int n= count(s.begin(),s.end(),c);
    n*=1ll;
    res=(n+1)*(n)/2;
    return res;
}
int main(){
    return 0;
}


