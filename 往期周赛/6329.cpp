#include "map"
#include "vector"
#include "algorithm"
using  namespace std;
long long makeSubKSumEqual(vector<int>& arr, int k) {
    long long ans=0,cmp=0;
    int flag=0,len=arr.size()%k?arr.size()/k+1:arr.size()/k;
    for(int i=0;i<k;i++){
        cmp=0;
        for(int j=i,flag=0;flag<len;j=(j+k)%arr.size(),flag++){
            cmp+=arr[j];
        }
        cmp=cmp-(cmp/len)*len<(cmp/len+1)*len-cmp?cmp/len:cmp/len+1;
        for(int j=i,flag=0;flag<len;j=(j+k)%arr.size(),flag++){
            ans+=arr[j]-cmp>0?arr[j]-cmp:cmp-arr[j];
        }
    }
    return ans;
}

int main(){
    vector<int>arr={2,5,5,7};
    makeSubKSumEqual(arr,3);
    return 0;
}
