//
// Created by zengyou on 2023/10/15.
//
#include "iostream"
#include "map"
#include "vector"
#include "algorithm"
#include "string"
#include "unordered_map"
using  namespace std;
unordered_map<string,int>s1_map,s2_map;
void strSplit(string &s1,bool type){
    int left=0,right=0;
    while(right<s1.size()){
        while(right<s1.size()&&s1[right]!=' ')right++;
        if(type==true)s1_map[s1.substr(left,right-left)]++;
        else s2_map[s1.substr(left,right-left)]++;
        right++;
        left=right;
    }

}
vector<string> uncommonFromSentences(string s1, string s2) {

    strSplit(s1,true);
    strSplit(s2,false);
    vector<string>res;
    for(auto it:s1_map){
        if(!s2_map.count(it.first))res.push_back(it.first);
    }
    for(auto it:s2_map){
        if(!s1_map.count(it.first))res.push_back(it.first);
    }
    return res;
}

int main(){
//    string s1 = "this apple is sweet", s2 = "this apple is sour";
    string s1="apple apple", s2 = "banana";
    uncommonFromSentences(s1,s2);
    return 0;
}