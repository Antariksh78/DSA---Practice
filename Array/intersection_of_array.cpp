#include <iostream>
using namespace std;
#include <bits/stdc++.h>

void Intersection_of_Array(int arr[],int arr1[],int n,int n1){
    int i=0;
    int j=0;
    vector<int> array;
    while(i<n && j<n1){
        if(arr[i]<arr1[j]){
            i++;
        }
        else if(arr[i]>arr1[j]){
            j++;
        }
        else{
            array.push_back(arr[i]);
            i++;
            j++;
        }
    }
    for(auto it:array){
        cout<<it<<" ";
    }
}

int main(){
    int n;
    cout<<"Enter the value of n : ";cin>>n;
    int arr[100];
    cout<<"Enter the values of array1 ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int n1;
    cout<<"Enter the value of n1 : ";cin>>n1;
    int arr1[100];
    cout<<"Enter the values of array1 ";
    for(int i=0;i<n1;i++){
        cin>>arr1[i];
    }
    Intersection_of_Array(arr,arr1,n,n1);
}