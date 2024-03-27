//
// Created by zengyou on 2023/11/17.
//
#include "stdio.h"




void solve(){
    int nums[10][11];
    //初始化：杨辉三角两侧均为1
    for(int i=0;i<10;i++){
        nums[i][0]=nums[i][i]=1;
    }

    //计算 num[i][j]=nums[i-1][j-1]+nums[i-1][j]
    for(int i=1;i<10;i++){
        for(int j=1;j<i;j++){
            nums[i][j]=nums[i-1][j-1]+nums[i-1][j];
        }
    }

    //打印数组
    for(int i=0;i<10;i++){
        //打印空格
        for(int j=0;j<10-i;j++)printf("   ");

        for(int j=0;j<=i;j++){
            printf("   %d  ",nums[i][j]);
        }
        printf("\n");
    }

}


int main(){


    return 0;
}