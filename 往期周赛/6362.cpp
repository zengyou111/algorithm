//
// Created by zengyou on 2023/4/2.
//

#include "iostream"
#include "string.h"
using namespace std;

int findTheLongestBalancedSubstring(string s) {
    int ans=0,left=0,right=0,cmp=0;
    for(int i=1;i<s.size();i++){
        while(i<s.size()&&(s[i]!='1'||s[i-1]!='0'))i++;
        if(i==s.size())return ans;
        right=i,left=i-1;
        cmp=2;
        while(right<s.size()&&left>=0&&s[right]=='1'&&s[left]=='0'){
            cmp+=2;
            right++,left--;
        }
        ans=ans>cmp?ans:cmp;
    }
    return ans;
}

int main(){
    findTheLongestBalancedSubstring("");
}