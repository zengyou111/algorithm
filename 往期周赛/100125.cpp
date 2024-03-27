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

int dis_two(int n,int limit){
    int res=0;
    if(limit>=n){
        res=n+1;
    }else if(n>2*limit){
        return 0;
    }else {
        return 2*limit-n+1;
    }
}

int distributeCandies(int n, int limit) {
    int res=0;
    if(limit>=n){
        for(int i=0;i<=n;i++){
            res+= dis_two(n-i,limit);
        }
    }else{
        for(int i=0;i<=limit;i++){
            res+= dis_two(n-i,limit);
        }
    }
    return res;
}

int main(){
    cout<<distributeCandies(5,2)<<endl;
    cout<<distributeCandies(3,3)<<endl;
    return 0;
}


