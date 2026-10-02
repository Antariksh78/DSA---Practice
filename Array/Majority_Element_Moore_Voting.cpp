#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int Moore_Voting(int arr[],int n){
    int cand=arr[0];
    int count = 0;
    for(int i=0;i<n;i++){
        if(arr[i]==cand){
            count++;
        }
        else{
            count--;
            if(count==0){
                cand = arr[i];
                count++;
            }
        }
    }
    return cand;
}

int Majority_Element(int arr[],int n){
    int cand = Moore_Voting(arr,n);
    map<int,int> mpp;
    for(int i=0;i<n;i++){
        mpp[arr[i]]++;
    }
    if(mpp[cand]>n/2){
        cout<<"Majority Element Exists and it is : "<<cand;
    }
    else{
        cout<<"No Majority Element Exists!";
    }
}

int main(){
    int n;
    cout<<"Enter the value of n : ";cin>>n;
    int arr[100];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    Majority_Element(arr,n);
}