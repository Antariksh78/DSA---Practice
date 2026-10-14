#include <bits/stdc++.h>
using namespace std;

int minimum_in_rotated_array(vector<int> arr){
    int n = arr.size();
    int low = 0;
    int high = n-1;
    int ans = INT_MAX;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(arr[low] == arr[mid] && arr[mid] == arr[high]){
            low = low+1;
            high = high-1;
        }
        if(arr[low]<=arr[mid]){
            int ans = min(ans,arr[low]);
            low = mid+1;
        }
        else{
            int ans = min(ans,arr[mid]);
            high = mid-1;
        }
        
        
    }
}

int main(){
    int n;cout<<"Enter the value of n : ";cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;cout<<"Enter the value of target : ";cin>>k;
    
}