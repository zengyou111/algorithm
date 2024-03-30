//
// Created by zengyou on 2024/3/28.
//
    #include "bits/stdc++.h"
    using namespace std;
    int mod=1'000'000'007;
    int firstDayBeenInAllRooms(vector<int>& nextVisit) {
        int n=nextVisit.size();
        vector<long>f(n,0);
        f[0]=1;
        for(int i=1;i<n;i++){
            f[i]=(f[i-1]+f[i-1]-f[nextVisit[i-1]]+2);
        }
        return f[n]%mod;
    }

    int main(){
        vector<int>nextVisit={0,1,2,0};
        cout<<firstDayBeenInAllRooms(nextVisit);
        return 0;
    }

