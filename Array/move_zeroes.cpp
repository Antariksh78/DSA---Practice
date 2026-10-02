#include <iostream>
using namespace std;
#include <bits/stdc++.h>

void Move_Zeroes(int arr[],int n){
    int j=0;
    for(int i=0;i<n;i++){
        if(arr[i]!=0){
            arr[j]=arr[i];
            j++;
        }
    }
    for(int i=j;i<n;i++){
        arr[i] = 0;
    }
}

int main(){
    int n;
    cout<<"Enter the value of n : ";cin>>n;
    int arr[100];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    Move_Zeroes(arr,n);
}