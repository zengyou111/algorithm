//
// Created by zengyou on 2024/2/18.
//
#include "bits/stdc++.h"
using namespace std;

bool isPrime(int num){
    if(num==1||num==4)
        return false;
    if(num==2||num==3)
        return true;
    if(num %6!= 1&&num %6!=5)
        return false ;
    int tmp =sqrt(num);
    for(int i=5;i<=tmp;i+=6) {
        if(num%i==0||num%(i+2)==0)
            return false ;
    }
    return true;
}

int mostFrequentPrime(vector<vector<int>>& mat) {
    unordered_map<int,int>ma;
    vector<vector<int>>dirs={
            {-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}
    };
    int m=mat.size(),n=mat[0].size();
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            for(auto &dir:dirs){
                int tmp=0;
                int x=i,y=j;
                while(x>=0&&x<m&&y>=0&&y<n){
                    tmp*=10;
                    tmp+=mat[ x ][ y ];
                    x=x+dir[0],y=y+dir[1];
                }
                if(tmp>10&& isPrime(tmp)){
                   ma[tmp]++;}
            }
        }
    }
    vector<pair<int,int>>vec;
    for(auto &[k,v]:ma){
        vec.push_back({k,v});
    }
    sort(vec.begin(),vec.end(),[&](pair<int,int>&a,pair<int,int>&b)->bool {
        return a.second>b.second;
    });

    if(vec.size()==0)return -1;
    vector<int>res;
    for(int i=0;i<vec.size();i++){
        if(vec[i].second==vec[0].second){
            res.emplace_back(vec[i].first);
        }
    }

    return *max_element(res.begin(),res.end());
}

int main(){
    vector<vector<int>>test={{1,1},{9,9},{1,1}};
    cout<< mostFrequentPrime(test);
    return 0;
}

