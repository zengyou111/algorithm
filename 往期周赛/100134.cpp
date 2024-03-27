//
// Created by zengyou on 2023/11/26.
//
#include "bits/stdc++.h"
using namespace std;
int beautifulSubstrings(string s, int k) {
    int len=s.size();
    int cntvo=0,cntco=0,res=0;
    vector<int>vo(len,0),co(len,0);
    for(int i=0;i<len;i++){
        if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')cntvo++;
        else cntco++;
        vo[i]=cntvo;
        co[i]=cntco;
    }
    for(int i=0;i<len;i++){
        if(vo[i]==co[i]&&(vo[i]*co[i])%k==0)res++;
    }
    for(int i=0;i<len;i++){
        for(int j=i+1;j<len;j++){
            cntvo=vo[j]-vo[i];
            cntvo=co[j]-co[i];
            if(cntvo==cntvo&&(cntvo*cntvo)%k==0){
                cout<<i<<" "<<j<<endl;
                res++;
            }
        }
    }
    return res;
}
int main(){
    string s="baeyh";
    beautifulSubstrings(s,2);
    return 0;
}
