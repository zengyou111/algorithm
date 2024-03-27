//
// Created by zengyou on 2024/2/18.
//

#include "bits/stdc++.h"
using namespace std;
int countPrefixSuffixPairs(vector<string>& words) {
    int n=words.size(),res=0;
    for(int i=n-1;i>0;i--){
        for(int j=i-1;j>=0;j--){
            if(words[i].size()>words[j].size())continue;
            int s=words[i].size(),t=words[j].size();
            bool tmp=true;
            for(int k=0;k<t;k++){
                cout<<words[j][k]<<" "<<words[i][k]<<" "<<words[i][s-t+k]<<endl;
                if((words[j][k]!=words[i][k])||words[j][k]!=words[i][s-t+k])
                    tmp=false;
                break;
            }
            if(tmp)res++;
        }
    }
    return res;
}

int main(){
    vector<string>words={"abc","aba"};
    cout<<countPrefixSuffixPairs(words);
    return 0;
}