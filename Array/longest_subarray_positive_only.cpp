#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int Longest_Subarray_Positives_only(int arr[],int n,int k){
    int left = 0;
    int right = 0;
    int sum = arr[0];
    int maxilen = 0;
    while(right<n){
        while(sum>k){
            sum-=arr[left];
            left++;
        }
        sum+=arr[right];
        right++;
        if(sum==k){
            maxilen = max(maxilen,right-left+1);
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
    cout<<Longest_Subarray_Positives_only(arr,n,k);
}