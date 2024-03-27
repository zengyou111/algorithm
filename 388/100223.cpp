//
// Created by zengyou on 2024/3/10.
//

#include "bits/stdc++.h"
using namespace std;

vector<string> shortestSubstrings(vector<string>& arr) {
    int n=arr.size();
    vector<string>res(n);
    vector<set<string>>s(n);
    for(int i=0;i<n;i++){
        int m=arr[i].size();
        for(int j=0;j<m;j++){
            for(int k=j;k<m;k++){
                s[i].insert(arr[i].substr(j,k-j+1));
            }
        }
    }
    for(int i=0;i<n;i++){
        vector<string>tmp;
        int len=INT_MAX;
        for(auto k:s[i]){
            bool flag=true;
            for(int j=0;j<n;j++){
                if(j==i)continue;
                if(s[j].count(k)){
                    flag= false;
                    break;
                }
            }
            if(flag){
                tmp.emplace_back(k);
                len=len<k.size()?len:k.size();
            }

        }
        if(tmp.size()==0) {
            res[i]="";
        }else{
            sort(tmp.begin(),tmp.end());
            int t=0;
            while(tmp[t].size()!=len)t++;
            res[i]=tmp[t];
        }
    }
    return res;
}


int main(){
    vector<string>arr={"gfnt","xn","mdz","yfmr","fi","wwncn","hkdy"};
    shortestSubstrings(arr);
    return 0;
}