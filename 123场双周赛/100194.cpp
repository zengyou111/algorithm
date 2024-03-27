//
// Created by zengyou on 2024/2/3.
//
#include "bits/stdc++.h"

using namespace  std;

int numberOfPairs(vector<vector<int>>& points) {
    int res=0;
    sort(points.begin(),points.end(),[&](vector<int>&a,vector<int>&b)->bool {
        return a[0]<b[0]||(a[0]==b[0]&&a[1]>b[1]);
    });
    int n=points.size();
    for(int i=0;i<n-1;i++){
        int l_x=points[i][0],l_y=points[i][1];
        for(int j=i+1;j<n;j++){
            if(points[j][1]>l_y)continue;
            if(n==2)return 1;
            int r_x=points[j][0],r_y=points[j][1];
            for(int k=0;k<n;k++){
                if(k==i||k==j)continue;
                int x=points[k][0],y=points[k][1];
                if((x==l_x||x==r_x)&&(y>=l_y&&y<=r_y))continue;
                else if((y==l_y||y==r_y)&&(x>=l_x&&x<=r_x))continue;
                else if(x>=l_x&&x<=r_x&&y<=l_y&&y>=r_y)continue;
                else {
                    cout<<"r_x:"<<r_x<<"r_y:"<<r_y<<"l_x:"<<l_x<<"l_y:"<<l_y<<"x:"<<x<<"y:"<<y<<endl;
                    res++;
                }
            }
        }
    }
    return res;
}

int main(){
    vector<vector<int>>test={{0,0},{0,6},{0,3},{1,0}};
    numberOfPairs(test);
    return 0;
}

///*

