#include <iostream>
using namespace std;
#include <bits/stdc++.h>

void Reverse_Array(int arr[],int low,int high){
    int i=low;
    int j=high;
    while(i<j){
        swap(arr[i],arr[j]);
        i++;
        j--;
    }

}

void Rotate_Array(int arr[],int n,int k){
    Reverse_Array(arr,0,k-1);
    Reverse_Array(arr,k,n-1);
    Reverse_Array(arr,0,n-1);
}

int main(){
    int n;
    cout<<"Enter the value of n : ";cin>>n;
    int arr[100];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;cout<<"Enter the value of K : ";cin>>k;
    Rotate_Array(arr,n,k);
}