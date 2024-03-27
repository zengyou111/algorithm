//
// Created by zengyou on 2023/11/26.
//
#include<bits/stdc++.h>
using namespace std;
bool areSimilar(vector<vector<int>>& mat, int k) {
    vector<vector<int>>mat2(mat.begin(),mat.end());
    int m=mat.size(),n=mat[0].size();
    for(int i=0;i<m;i++){
        reverse(mat[i].begin(),mat[i].end());
        if(i%2==0){
            reverse(mat[i].begin(),mat[i].begin()+n-k);
            reverse(mat[i].begin()+n-k,mat[i].end());
        }else{
            reverse(mat[i].begin(),mat[i].begin()+k);
            reverse(mat[i].begin()+k,mat[i].end());
        }
        for(int j=0;j<n;j++){
            if(mat[i][j]!=mat2[i][j])return false;
        }
    }
    return true;
}
int main(){
    vector<vector<int>>mat1={{1,2,1,2},{5,5,5,5},{6,3,6,3}};
    areSimilar(mat1,2);
    return 0;
}