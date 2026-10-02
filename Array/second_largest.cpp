#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int Second_Largest(int arr[],int n){
    int largest = arr[0];
    int Slargest = INT_MIN;
    for(int i=1;i<n;i++){
        if(arr[i]>largest){
            Slargest = largest;
            largest = arr[i];
        }
        if(arr[i]<largest && arr[i]>Slargest){
            Slargest = arr[i];
        }
    }
    if(Slargest == INT_MIN){
        cout<<"No Second largest Exists";
        return false;
    }
    return Slargest;
}

int main(){
    int n;
    cout<<"Enter the value of n : ";cin>>n;
    int arr[100];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<Second_Largest(arr,n);
}