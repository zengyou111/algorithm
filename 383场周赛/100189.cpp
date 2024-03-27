//
// Created by zengyou on 2024/2/4.
//
#include "bits/stdc++.h"
using namespace  std;
vector<vector<int>>dirs={{-1,0},{1,0},{0,-1},{0,1}};


int adjust(vector<vector<int>>&images,int x,int y,int threshold){
    for(int i=x;i<=x+2;i++){
        for(int j=y;j<=y+2;j++){
            for(auto &dir:dirs){
                int m=dir[0]+i,n=dir[1]+j;
                if(!(m>=x&&m<=x+2&&n>=y&&n<=y+2&&abs(images[m][n]-images[i][j]<=threshold))){
                    return -1;
                }
            }
        }
    }
    int sum=0;
    for(int i=x;i<=x+2;i++){
        for(int j=y;j<=y+2;j++){
            sum+= images[i][j];
        }
    }
    sum/=9;
}


vector<vector<int>> resultGrid(vector<vector<int>>& image, int threshold) {
    int m=image.size(),n=image[0].size();
    vector<vector<int>>res(m,vector<int>(n,0));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            int sum=0,cnt=0,tmp=0,num=0;
            //第一个区域
            if(i+2<m&&j+2<n){
                num++;
                tmp=adjust(image,i,j,threshold);
                if(tmp!=-1){
                    cnt++;
                    sum+=tmp;
                }
            }


            res[i][j]=sum/num;



        }
    }
}
int main(){

    return 0;
}

