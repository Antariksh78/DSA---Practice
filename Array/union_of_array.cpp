#include <iostream>
using namespace std;
#include <bits/stdc++.h>

void Union_of_two_Arrays(int arr1[],int arr2[],int n1,int n2){
    int i=0;
    int j=0;
    vector<int> array;
    while(i<n1 && j<n2){
        if(arr1[i]<=arr2[j]){
            if( array.size()==0 || array.back()!=arr1[i]){
                array.push_back(arr1[i]);
            }
            i++;
        }
        else{
            if( array.size()==0 || array.back()!=arr2[j]){
                array.push_back(arr2[j]);
            }
            j++;
        }
    }
    while(i<n1){
        if( array.size()==0 || array.back()!=arr1[i]){
                array.push_back(arr1[i]);
            }
            i++;
    }
    while(j<n2){
        if( array.size()==0 || array.back()!=arr2[j]){
                array.push_back(arr2[j]);
            }
            j++;
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
    Union_of_two_Arrays(arr,arr1,n,n1);
}