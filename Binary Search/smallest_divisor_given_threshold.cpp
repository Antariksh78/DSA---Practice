#include <bits/stdc++.h>
using namespace std;

int answer(vector<int> arr,int mid){
    int ans = 0;
    for(auto it:arr){
        ans+=ceil((double)it/mid);
    }
    return ans;
}

int smallest_divisor(vector<int> arr,int t){
    int low = INT_MAX;
    int high = INT_MIN;
    for(auto it:arr){
        low = min(low,it);
        high = max(high,it);
    }
    int ans = high;
    while(low<=high){
        int mid = low +(high-low)/2;
        if(answer(arr,mid)<=t){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return ans;
}

int main(){
    int n;cout<<"Enter the value of N : ";cin>>n;
    vector<int> arr(n);cout<<"Enter the elements of the array : ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int t;cout<<"Enter the value of threshold : ";cin>>t;
    cout<<smallest_divisor(arr,t);
}