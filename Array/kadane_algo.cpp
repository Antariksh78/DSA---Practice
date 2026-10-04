#include <bits/stdc++.h>
using namespace std;

int kadane_algo(int arr[],int n){
    int sum = 0;
    int maxi=INT_MIN;
    for(int i=0;i<n;i++){
        if(sum<0){
            sum=0;
        }
        sum+=arr[i];
        maxi=max(sum,maxi);
    }
    return maxi;
}

int main(){
    int n;
    cout<<"Enter the value of n : ";
    cin>>n;
    int arr[100];
    cout<<"Enter the value of array elements : ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<kadane_algo(arr,n);
}