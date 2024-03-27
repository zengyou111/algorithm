//
// Created by zengyou on 2024/2/4.
//

#include "bits/stdc++.h"
using namespace  std;
int minimumTimeToInitialState(string word, int k) {
    int len=word.size();
    int res=0,cnt=0;
    for(int i=k;i<len;i+=k){
        res++;
        cnt=len-i;
        string tmp1=word.substr(i,cnt);
        string tmp2=word.substr(0,cnt);
        cout<<"tmp1:"<<tmp1<<",tmp2:"<<tmp2<<endl;
        if(tmp1==tmp2)return res;
    }
    cnt=len-res*k;
    if(word.substr(0,cnt)==word.substr(res*k,cnt))return res;
    return res+1;
}
int main(){
    minimumTimeToInitialState("abacaba",3);
    return 0;
}