#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int Lnogest_Subarray_sum_k(int arr[],int n,int k){
    map<int,int> mpp;
    int sum=0;
    int maxilen=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum==k){
            maxilen = max(maxilen,i+1);
        }
        int rem = sum-k;
        if(mpp.find(rem) != mpp.end()){
            int len = i-mpp[rem];
            maxilen = max(maxilen,len);
        }
        if(mpp.find(sum)==mpp.end()){
            mpp[sum] = i;
        }
    }
    return maxilen;
}

int main(){
    int n;
    cout<<"Enter the value of n : ";cin>>n;
    int arr[100];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cout<<"Enter the value of k";
    cin>>k;
    cout<<Lnogest_Subarray_sum_k(arr,n,k);
}