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

int minThree(vector<int>nums,int i,int j,int k){
    if(j-i==2){
        int M=max(max(nums[i],nums[i+1]),nums[i+2]);
        if(M>=k)return 0;
        return M>=k?0:k-M;
    }else if(j-i==3){
        if(nums[i+1]>=k||nums[i+2]>=k)return 0;
        int tmp=max(max(nums[i],nums[i+1]),nums[i+2]);
        tmp= tmp>=k?0:k-tmp;
        int tmp2=max(max(nums[i+1],nums[i+2]),nums[i+3]);
        tmp2=tmp2>=k?0:k-tmp2;
        return tmp+tmp2;
    }else{
        int tmp=nums[2]>=k?0:k-nums[2];
        int M_left=max(max(nums[i],nums[i+1]),nums[i+2]);
        int M_right=max(max(nums[i+2],nums[i+3]),nums[i+4]);
        M_left=M_left>=k?0:k-M_left;
        M_right=M_right>=k?0:k-M_right;
        return
    }

}




long long minIncrementOperations(vector<int>& nums, int k){
    if(nums.size()==3){
        int M=max(max(nums[0],nums[1]),nums[2]);
        return M>=k?0:k-M;
    }else if(nums.size()==4){
        if(nums[1]>=k||nums[2]>=k)return 0;
        int tmp=max(max(nums[0],nums[1]),nums[2]);
        tmp= tmp>=k?0:k-tmp;
        int tmp2=max(max(nums[1],nums[2]),nums[3]);
        tmp2=tmp2>=k?0:k-tmp2;
        return tmp+tmp2;
    }else{
        for(int i=4;i<nums.size()-4;i++){

        }
    }
}





//long long minIncrementOperations(vector<int>& nums, int k) {
//    int tmp=2;
//    long long res=0;
//    bool flag= false;
//    for(int i=0;i<nums.size()-3;i++){
//        tmp=i+2;
//        flag=false;
//        for(int j=i+2;j>=i;j--){
//            if(nums[j]>=k){
//                flag= true;
//                break;
//            }
//            if(k-nums[j]<k-nums[tmp]){
//                tmp=j;
//            }
//        }
//        if(flag)continue;
//        res+=(k-nums[tmp]);
//        nums[tmp]=k;
//    }
//    return res;
//}
int main(){
    vector<int>nums={2,3,0,0,2};
    minIncrementOperations(nums,4);
    return 0;
}

