#include <bits/stdc++.h>
using namespace std;

int subarray_xor_k_optimal(int arr[],int n,int k){
    int xr=0;
    map<int,int> mpp;
    mpp[xr]++;
    int count = 0;
    for(int i=0;i<n;i++){
        xr=xr^arr[i];
        int x = xr^k;
        count+=mpp[x];
        mpp[xr]++;
    }
    return count;
}

int main(){
    int n;
    cout<<"Enter the value of n : ";
    cin>>n;
    int arr[100];
    cout<<"Enter the value of array elements : ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;cout<<"Enter the value of k ";cin>>k;
    cout<<subarray_xor_k_optimal(arr,n,k);
}