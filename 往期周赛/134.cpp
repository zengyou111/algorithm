//
// Created by zengyou on 2023/10/29.
//
#include "vector"
#include "algorithm"
#include "string"
#include "math.h"
#include "unordered_map"
#include "set"
using  namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int currentSum=0,totalSum=0,start=0,cnt=1;
    for(int i=0;i<gas.size();i++){
        for(;i<gas.size();i++){
            currentSum+=gas[i]-cost[i];
            totalSum+=gas[i]-cost[i];
            if(currentSum<0){
                start=(i+1)%gas.size();
                break;
            }
        }
        if(i==gas.size())return 0;
        totalSum+=(gas[i]-cost[i]);
    }
    if(totalSum<0)return -1;
    totalSum=gas[start];
    for(;cnt<gas.size()-1;cnt++){
        start=(start+1)%gas.size();
        totalSum+=(gas[start]-cost[start]);
        if(totalSum<0)return -1;
    }
    return totalSum-cost[(start+1)%gas.size()]>=0;
}


int main(){
    vector<int>gas={1,2,3,4,5};
    vector<int>cost={3,4,5,1,2};
    return canCompleteCircuit(gas,cost);
}
