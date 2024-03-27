//
// Created by zengyou on 2024/3/16.
//

#include "bits/stdc++.h"

using namespace std;
int sumOfEncryptedInt(vector<int>& nums) {
    int res=0;
    for(auto &num:nums){
        int tmp=0,cnt=0;
        do{
            tmp=max(tmp,num%10);
            num/=10;
            cnt++;
        }while(num);
        for(int i=0;i<cnt;i++){
            num+=tmp;
            num*=10;
        }
        res+=num;
    }
    return res;
}
int main(){
    return 0;
}