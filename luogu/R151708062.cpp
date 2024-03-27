//
// Created by zengyou on 2024/3/19.
//
#include"bits/stdc++.h"
using namespace std;
using LL=long long;
int main(){
    LL m,n,a;
    cin>>m>>n>>a;
    cout<<( (a+m-1)/a )*( (a+n-1)/a);
}
