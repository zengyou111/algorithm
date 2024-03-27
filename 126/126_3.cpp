//
// Created by zengyou on 2024/3/16.
//
#include "bits/stdc++.h"

using namespace std;

string minimizeStringValue(string s) {
    vector<int>m(26,0);
    vector<int>tmp;
    int n=s.size();
    for(int i=0;i<n;i++){
        if(s[i]>='a'&&s[i]<='z'){
            m[ s[i]-'a' ]++;
        }else{
            tmp.push_back(i);
        }
    }
    for(auto idx:tmp){
        int ch=0;
        for(int i=1;i<26;i++){
            if(m[i]<m[ch])ch=i;
        }
        s[idx]='a'+ch;
        m[ch]++;
    }
    return s;
}

int main(){
    string s="abcdefghijklmnopqrstuvwxy??";
    cout<<minimizeStringValue(s);
    return 0;
}

