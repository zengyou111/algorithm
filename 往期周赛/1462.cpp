//
// Created by zengyou on 2023/11/2.
//
#include "vector"
#include "algorithm"
#include "string"
#include "math.h"
#include "unordered_map"
#include "set"
#include "map"
#include "queue"
using  namespace std;

vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
    vector<int>edg(numCourses,0);
    vector<bool>res(queries.size(),false);
    vector<vector<int>>pre(numCourses);
    map<int,set<int>>m;
    for(vector<int>&x:prerequisites){
        edg[x[1]]++;
        pre[x[0]].push_back(x[1]);
    }
    queue<int>q;
    for(int i=0;i<numCourses;i++){
        if(edg[i]==0){
            q.push(i);
        }
    }
    int len=0;
    while(!q.empty()){
        len++;
        int x=q.front();
        q.pop();
        for(int &num:pre[x]){
            if(--edg[num]==0){
                q.push(num);
            }
        }
    }
    if(len<numCourses)return res;
    for(int i=0;i<numCourses;i++){
        for(int &x:pre[i]){
            m[x].emplace(i);
        }
    }
    int len2=queries.size();
    for(int i=0;i<len2;i++){
        if(m[queries[i][0]].find(queries[i][1])!=m[queries[i][0]].end()){
            res[i]=true;
        }
    }
    return res;
}


int main(){
    vector<vector<int>>prerequisites={{1,0}};
    vector<vector<int>>queries={{0,1},{1,0}};
    checkIfPrerequisite(2,prerequisites,queries);
    return 0;
}


