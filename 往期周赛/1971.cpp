//
// Created by zengyou on 2023/11/11.
//
#include "iostream"
#include "vector"
#include "algorithm"
#include "string"
#include "math.h"
#include "unordered_map"
#include "set"
#include "map"
#include "queue"
using  namespace std;


    vector<int>fa;

    int find(int x){
        if(fa[x]==x)return x;
        return fa[x]=find(fa[x]);
    }

    void union__(int x,int y){
        fa[find(y)]=find(x);
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        fa.resize(n);
        for(int i=0;i<n;i++){
            fa[i]=i;
        }
        for(vector<int>&x:edges){
            union__(x[0],x[1]);
        }
        return find(source)==find(destination);
    }



int main(){

    vector<vector<int>>edges={{0,1},{1,2},{2,0}};
    validPath(3,edges,0,2);
    return 0;
}


