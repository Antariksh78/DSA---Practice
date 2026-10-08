#include <bits/stdc++.h>
using namespace std;

int subarray_sum_k_count(int arr[],int n,int k){
    unordered_map<int,int> mpp;
    mpp[0]=1;
    int prefix_sum=0;
    int count=0;
    for(int i=0;i<n;i++){
        prefix_sum+=arr[i];
        int remove = prefix_sum-k;
        count+=mpp[remove];
        mpp[prefix_sum]++;
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
    int k;cout<<"Enter the value of  k ";cin>>k;
    cout<<subarray_sum_k_count(arr,n,k);
}