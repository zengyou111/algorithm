//
// Created by zengyou on 2023/10/15.
//
#include "iostream"
#include "map"
#include "vector"
#include "algorithm"
#include "string"
using  namespace std;

string shortestBeautifulSubstring(string s, int k) {
    int left=0,right=0,cnt=0;
    vector<string>vec_str;
    while(right<s.size()){
        while(right<s.size()&&cnt<k){
            if(s[right]=='1')cnt++;
            right++;
        }
        if(right<=s.size()){
            if(cnt==k){
                while(s[left]!='1')left++;
                vec_str.push_back(s.substr(left,right-left));
                left++,cnt--;
            }
            else break;
        }

    }
    if(vec_str.empty())return "";
    sort(vec_str.begin(),vec_str.end(),[&](const string &a,const string &b)->bool {
        a.length()<b.length();
    });
    vector<string>res;
    int i=0;
    while(i<vec_str.size()&&vec_str[i].length()==vec_str[0].length()){
        res.push_back(vec_str[i]);
        i++;
    }
    sort(res.begin(),res.end());
    return res[0];
}



int main(){
    string res=shortestBeautifulSubstring("1011",2);
    std::cout<<res;
    return 0;
}

