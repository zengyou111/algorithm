//
// Created by zengyou on 2024/2/18.
//
#include "bits/stdc++.h"
using namespace std;
int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
    unordered_set<string>s;
    int res=0;
    string tmp1="",tmp2="";
    for(int i=0;i<arr1.size();i++){
        tmp1= to_string(arr1[i]);
        for(int j=0;j<tmp1.size();j++){
            s.insert(tmp1.substr(0,j+1));
        }
    }
    for(int i=0;i<arr2.size();i++){
        tmp2= to_string(arr2[i]);
        for(int j=0;j<tmp2.size();j++){
            if(s.count(tmp2.substr(0,j+1))){
                res=max(res,j+1);
            }else {
                break;
            }
        }
    }
    return res;
}
int main(){

    return 0;
}

