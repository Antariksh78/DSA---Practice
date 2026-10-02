#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int maximum_subarray_sum_brute(int arr[],int n){
    int maxi = INT_MIN;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=arr[j];
        }
        maxi = max(maxi,sum);
    }
    return maxi;
}

int main(){
    int n;
    cout<<"Enter the value of n : ";cin>>n;
    int arr[100];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<maximum_subarray_sum_brute(arr,n);
}