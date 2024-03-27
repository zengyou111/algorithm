#include "vector"
#include "algorithm"
#include "string"
#include "unordered_map"
#include "set"
using  namespace std;
//
// Created by zengyou on 2023/10/28.
//
int minChanges(string s) {
    vector<int>tmp(s.size(),0);
    int res=INT_MAX;
    int cnt=0,sum= count(s.begin(),s.end(),'1');
    for(int i=0;i<s.size();i++){
        if(s[i]=='1'){
            cnt++;
        }
        tmp[i]=cnt;
    }
    int tmp1=0,tmp2=0;
    for(int i=1;i<s.size();i+=2){
        if(tmp[i/2]==tmp[i]&&(i+1)%4==0){
            tmp1=0;
        }else{
            tmp1=min(i+1-tmp[i],tmp[i]);
        }
        int a=tmp[tmp.size()-1]-tmp[i];
        int b=tmp.size()-(i+1)-a;
        if(tmp[i+(tmp.size()-(i+1))/2]-tmp[i]==a&&(tmp.size()-(i+1))%4==0){
            tmp2=0;
        }else{
            tmp2=min(a,b);
        }
        res=min(res,tmp1+tmp2);
    }
    return res;
}

int main(){
    minChanges("010010");
    return 0;
}
