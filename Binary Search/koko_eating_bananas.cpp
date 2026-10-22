#include <bits/stdc++.h>
using namespace std;

int result(vector<int> arr,int k){
    int n = arr.size();
    int ans = 0;
    for(int i=0;i<n;i++){
        ans += ceil((double)arr[i]/k);
    }
    return ans;
}

int koko_eating_banana(vector<int> arr,int k){
    int n = arr.size();
    int low = 1;
    int high = arr[n-1];
    int ans = high;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(result(arr,mid)>k){
            low = mid+1;
        }
        else{
            ans = mid;
            high = mid-1;
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
    int k;cout<<"Enter the value of k : ";cin>>k;
    cout<<koko_eating_banana(arr,k);
}