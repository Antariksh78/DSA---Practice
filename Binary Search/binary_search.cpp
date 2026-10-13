#include <bits/stdc++.h>
using namespace std;

int binary_search(vector<int> arr,int k){
    int n = arr.size();
    int low = 0;
    int high = n-1;
    int ans = -1;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid]>k){
            high = mid-1;
        }
        else if(arr[mid]<k){
            low = mid+1;
        }
        else{
            return mid;
        }
    }
    return ans;
}

int recursive_binary_search(vector<int> arr,int low,int  high,int k){
    if(low>high) return -1;
    int mid = high+low/2;
    if(arr[mid]>k){
        return recursive_binary_search(arr,low,mid-1,k);
    }
    else if(arr[mid]<k){
        return recursive_binary_search(arr,mid+1,high,k);
    }
    else{
        return mid;
    }
}
// OVERFLOW CASE if the search space is not limited to arrays and can go upto INT_MAX then using mid as (low+high)/2; will cause an overflow case and thus the value of mid should be calculated as mid = low + (high-low)/2;
int main(){
    int n;cout<<"Enter the value of n : ";cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;cout<<"Enter the value of target : ";cin>>k;
    cout<<recursive_binary_search(arr,0,n-1,k);
}