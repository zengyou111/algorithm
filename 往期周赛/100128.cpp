//
// Created by zengyou on 2023/11/12.
//
#include<bits/stdc++.h>
using namespace std;

vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
    map<string,vector<string>>m;
    vector<string>res;
    for(vector<string>&x :access_times){
        m[x[0]].push_back(x[1]);
    }
    for(auto &it:m){
        sort(it.second.begin(),it.second.end());
        if(it.second.size()<3)continue;
        int len=it.second.size();
        for(int i=0;i<len-2;i++){
            int tmp1=stoi(it.second[i].substr(0,2))*60+stoi(it.second[i].substr(2,2));
            int tmp2=stoi(it.second[i+2].substr(0,2))*60+stoi(it.second[i+2].substr(2,2));
            if(tmp2-tmp1<60){
                res.push_back(it.first);
                break;
            }
        }
    }
    return res;
}

int main(){
    vector<vector<string>>e={{"a","0549"},{"b","0457"},{"a","0532"},{"a","0621"},{"b","0540"}};
    findHighAccessEmployees(e);
    return 0;
}

