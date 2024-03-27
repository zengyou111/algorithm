//
// Created by zengyou on 2023/7/27.
//
#include<iostream>
#include "vector"
#include "algorithm"
using namespace std;
void swap(vector<int>&arr,int i,int j){
    int tmp=arr[i];
    arr[i]=arr[j];
    arr[j]=tmp;
}
//调整堆
void heapify(vector<int>&arr,int len,int i){
    int largest=i,lson=2*i+1,rson=2*(i+1);
    if(lson<len&&arr[lson]>arr[largest])largest=lson;
    if(rson<len&&arr[rson]>arr[largest])largest=rson;
    if(largest!=i){
        swap(arr,i,largest);
        heapify(arr,len,largest);
    }
}

//建大顶堆
void buildMaxHeap(vector<int>&arr){
    for(int i=(arr.size()-1)/2;i>=0;i--){
        heapify(arr,arr.size(),i);
    }
}

//删除堆顶元素
int deleteHeapTop(vector<int>&arr,int len){
    swap(arr,0,len-1);
    heapify(arr,len-1,0);
    return arr[len-1];
}

int deleteGreatestValue(vector<vector<int>>& grid) {
    vector<int>tmp(grid.size(),0);
    int res=0;
    for(int i=0;i<grid.size();i++){
        buildMaxHeap(grid[i]);
    }
    for(int j=grid[0].size()-1;j>=0;j--){
        for(int i=0;i<grid.size();i++){
            tmp[i]=deleteHeapTop(grid[i],grid[0].size()-i);
        }
        res+=*max_element(tmp.begin(),tmp.end());
    }
    return res;
}
int main(){
    vector<vector<int>>grid({{1,2,4},{3,3,1}});
    deleteGreatestValue(grid);
    return 0;
}