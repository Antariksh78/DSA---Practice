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
int main(){
    int n;
    cout<<"Enter the value of n : ";cin>>n;
    int arr[100];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    Reverse_Array(arr,0,n);
}