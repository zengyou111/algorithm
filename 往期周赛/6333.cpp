//
// Created by zengyou on 2023/4/15.
//

#include "iostream"
#include "map"
#include "vector"
#include "algorithm"
using  namespace std;
vector<int> findColumnWidth(vector<vector<int>>& grid) {
    int flag=0,max=0,len=0;
    vector<int>res;
    for(int j=0;j<grid[0].size();j++){
        for(int i=0;i<grid.size();i++){
            max=0,len=0;
            if(grid[i][j]<0)len++;
            flag=abs(grid[i][j]);
            if(flag>=0&&flag<=9)len+=1;
            else if(flag>9&&flag<=99)len+=2;
            else if(flag>99&&flag<=999)len+=3;
            else if(flag>999&&flag<=9999)len+=4;
            else if(flag>9999&&flag<=99999)len+=5;
            else if(flag>99999&&flag<=999999)len+=6;
            else if(flag>999999&&flag<=9999999)len+=7;
            else if(flag>9999999&&flag<=99999999)len+=8;
            else if(flag>99999999&&flag<=999999999)len+=9;
            else len+=10;
            max=len>max?len:max;
        }
        res.push_back(max);
    }
    return res;
}
int main(){

    vector<vector<int>>ans={{-15,1,3},{15,7,12},{5,6,-2}};
    findColumnWidth(ans);
    return  0;
}
