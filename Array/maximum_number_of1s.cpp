#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int Maximum_Number_1s(int arr[],int n){
    int count =0;
    int maxi=0;
    for(int i=0;i<n;i++){
        if(arr[i]==1){
            count++;
        }
        if(arr[i]==0){
            maxi = max(maxi,count);
            count=0;
        }
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
    cout<<Maximum_Number_1s(arr,n);
}