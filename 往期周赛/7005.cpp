//
// Created by zengyou on 2023/9/2.
//

#include <numeric>
#include "map"
#include "vector"
#include "algorithm"
#include "string"
#include "unordered_map"
using namespace std;

bool check1(string &s1,string &s2){
    unordered_map<char,int>leftMap;
    unordered_map<char,int>rightMap;
    vector<int>left_l(26,0);
    vector<int>right_l(26,0);
    for(int i=0;i<s1.size();i++){
        if(i%2){
            leftMap[s1[i]]++;
            rightMap[s2[i]]++;
            left_l[s1[i]-'a']++;
            right_l[s2[i]-'a']++;
        }
    }
    sort(left_l.begin(),left_l.end());
    sort(right_l.begin(),right_l.end());
    for(auto i=leftMap.begin();i!=leftMap.end();i++){
        if(!rightMap.count(i->first)){
            return false;
        }
    }
    if(leftMap.size()!=rightMap.size())return false;
    for(int i=0;i<26;i++){
        if(left_l[i]!=right_l[i])return false;
    }
    return true;
}

bool check2(string &s1,string &s2){
    unordered_map<char,int>leftMap;
    unordered_map<char,int>rightMap;
    vector<int>left_l(26,0);
    vector<int>right_l(26,0);
    for(int i=0;i<s1.size();i++){
        if(!(i%2)){
            leftMap[s1[i]]++;
            rightMap[s2[i]]++;
            left_l[s1[i]-'a']++;
            right_l[s2[i]-'a']++;
        }
    }
    sort(left_l.begin(),left_l.end());
    sort(right_l.begin(),right_l.end());
    for(auto i=leftMap.begin();i!=leftMap.end();i++){
        if(!rightMap.count(i->first)){
            return false;
        }
    }
    if(leftMap.size()!=rightMap.size())return false;
    for(int i=0;i<26;i++){
        if(left_l[i]!=right_l[i])return false;
    }
    return true;
}

bool checkStrings(string s1, string s2) {
    return check1(s1,s2)&&check2(s1,s2);
}


int main(){
    int i=checkStrings("abcdba","cabdab");
    printf("%d",i);
    return 0;
}