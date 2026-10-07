#include <bits/stdc++.h>
using namespace std;

int leaders_in_array(int arr[],int n){
    int maxi = INT_MIN;
    vector<int> ans;
    for(int i=n-1;i>=0;i--){
        if(arr[i]>maxi){
            maxi = max(arr[i],maxi);
            ans.push_back(arr[i]);
        }

    }
    for(auto it:ans){
        cout<<it<<" ";
    }
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
    leaders_in_array(arr,n);
}