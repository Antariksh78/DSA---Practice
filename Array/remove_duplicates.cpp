#include <iostream>
using namespace std;
#include <bits/stdc++.h>

void remove_Duplicates(int arr[],int n){
    int count = 0;
    for(int i=0;i<n;i++){
        if(arr[count]!=arr[i]){
            count++;
            arr[count] = arr[i];
        }
    }
    for(int i=0;i<=count;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int n;
    cout<<"Enter the value of n : ";cin>>n;
    int arr[100];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    remove_Duplicates(arr,n);
}