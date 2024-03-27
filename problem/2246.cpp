//
// Created by zengyou on 2024/3/25.
//
#include "bits/stdc++.h"
using namespace std;
int mod=1'000'000'007;
int countTexts(string pressedKeys) {
    int n=pressedKeys.size(),ans=1,l=0,r=0;
    vector<int>dp(n+1,1);
    vector<int>dp2(n+1,1);
    for(int i=2;i<=n;i++){
        if(i==2){
            dp[i]=dp[i-1]+dp[i-2];
            dp2[i]=dp[i];
            continue;
        }
        dp[i]=((dp[i-1]+dp[i-2])%mod+dp[i-3])%mod;
        if(i==3){
            dp2[i]=dp[i];
        }else{
            dp2[i]=(((dp2[i-1]+dp2[i-2])%mod+dp2[i-3])%mod+dp2[i-4]%mod)%mod;
        }
    }
    while(l<n){
        while(r<n&&pressedKeys[r]==pressedKeys[l])r++;
        if(pressedKeys[l]>='2'&&pressedKeys[l]<='6'||pressedKeys[l]=='8'){
            ans=((1ll)*(ans%mod)*(dp[r-l]%mod))%mod;
        }else{
            ans=((1ll)*(ans%mod)*(dp2[r-l]%mod))%mod;
        }

        l=r;
    }
    return ans;
}
int main(){
//    cout<<countTexts( "22233")<<endl;
    cout<<countTexts("333333338888")<<endl;
//    cout<<countTexts("222222222222222222222222222222222222")<<endl;
    return 0;
}

