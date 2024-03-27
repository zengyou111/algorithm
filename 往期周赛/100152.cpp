//
// Created by zengyou on 2023/12/9.
//
#include "bits/stdc++.h"
using namespace std;

int removeAlmostEqualCharacters(string word) {
    int n=word.size();
    if(n==1)return 0;
    if(n==2) return abs(word[1]-word[0])<=1?1:0;
    int left=0,right=left+2,res=0;
    while(right<n){
        if(right-left==2){
            if(abs(word[left+1]-word[left])<=1){
                res++;
                left=right;
                right+=min(2,n-1-right);
            }else if(abs(word[right]-word[left+1])<=1){
                res++;
                left=right+1;
                if(left>=n)return res;
                right=left+ min(2,n-1-left);
//                if(right+1<n&& abs(word[right+1]-word[right])<=1){
//                    res++;
//                    left=right+1;
//                    right=left+min(2,n-1-left);
//                }else{
//                    res++;
//                    left=right;
//                    right= min(2,n-1-left);
//                }
            }else{
                left=right;
                right=left+min(2,n-1-left);
            }
        }else if(right-left==1){
            if(abs(word[right]-word[left])<=1){
                res++;
            }
            break;
        }else {
            break;
        }
    }
    return res;
}

int main(){

    vector<string>tmp{
                           "aaaaa",
                           "abddez",
                           "zyxyxyz",
                           "aca",
                           "acba",
                           "acaa",
                           "accaa",
    };
    string tmp4="accaa";
    cout<<removeAlmostEqualCharacters(tmp4)<<endl;
    for(auto &str:tmp){
        cout<<removeAlmostEqualCharacters(str)<<endl;
    }
    return 0;
}

