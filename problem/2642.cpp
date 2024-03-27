//
// Created by zengyou on 2024/3/26.
//
#include "bits/stdc++.h"
using namespace std;
class Graph {
private:
    vector<vector<int>>g;
    int n;
public:
//    Graph (){}
    Graph(int n, vector<vector<int>>& edges) {
        g.resize(n,vector<int>(n,INT_MAX/2));
        this->n=n;
        for(auto  e:edges){
            int x=e[0],y=e[1],d=e[2];
            g[x][y]=d;
        }
        for(int k=0;k<n;k++){
            g[k][k]=0;
            for(int i=0;i<n;i++){
                if(i==k)continue;
                for(int j=0;j<n;j++){
                    if(j==i)continue;
                    g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
                }
            }
        }
    }

    void addEdge(vector<int> edge) {
        int x=edge[0],y=edge[1],d=edge[2];
        if(d<g[x][y]){
            g[x][y]=d;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(j==i)continue;
                    g[i][j]=min({g[i][j],g[i][x]+g[x][y]+g[y][j]});
                }
            }
        }
    }

    int shortestPath(int node1, int node2) {
        return g[node1][node2]==INT_MAX/2?-1:g[node1][node2];
    }
};
int main(){
    Graph *g ;
    return 0;
}

