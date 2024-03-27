//
// Created by zengyou on 2024/3/17.
//
#include "bits/stdc++.h"
using namespace std;
int minimumDeletions(string word, int k) {
    int res=0;
    vector<int>m(26,0);
    for(char ch:word){
        m[ ch-'a' ]++;
    }
    sort(m.begin(),m.end());
    int l=0,r=25;
    while(l<r&&m[l]==0)l++;
    while(l<r){
        if(l>=r)return res;
        if(m[r]-m[l]<=k)return res;
        int cnt= count(m.begin(),m.end(),m[l]);
        int tmp2=cnt*m[l];
        int t=r;
        int tmp=0;
        while(m[t]-m[l]-k>0){
            tmp+=m[r]-m[l]-k;
            t--;
        }
        if( tmp <= tmp2 ){
            res+=tmp;
            m[r]-=tmp;
            r--;
        }else{
            res+=tmp2;
            while(cnt--){
                m[l]=0;
                l++;
            }
        }
    }
    return res;
}
int main(){
    cout<<minimumDeletions("zzfzzzzppfp",1);
//    cout<<minimumDeletions("klllurlrrul",1);
//   cout<<minimumDeletions("vvnowvov",2);
//   cout<<minimumDeletions("itatwtiwwi",1);
//    minimumDeletions("aabcaba",0);
    return 0;
}


