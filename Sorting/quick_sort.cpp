#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int partitions(int arr[],int low,int high){

    int pivot = arr[low];
    int i=low;
    int j=high;
    while(i<j){
        while(arr[i]<=pivot && i<=high-1){
            i++;
        }
        while(arr[j]>pivot && j>=low+1){
            j--;
        }
        if(i<j){
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[low],arr[j]);
    return j;
}

void Quick_Sort(int arr[],int low,int high){
    if(low<high){
        int pindex = partitions(arr,low,high);  
        Quick_Sort(arr,low,pindex-1);
        Quick_Sort(arr,pindex+1,high);
    }
}
int main(){
    int n;
    cout<<"Enter the value of n : ";cin>>n;
    int arr[100];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    Quick_Sort(arr,0,n);
}