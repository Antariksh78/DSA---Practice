#include <bits/stdc++.h>
using namespace std;

int lower_bound(vector<int> arr,int k){
    int n = arr.size();
    int low = 0;
    int high = n-1;
    int ans = INT_MAX;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(arr[mid]>=k){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return ans;
}

int upper_bound(vector<int> arr,int k){
    int n = arr.size();
    int low = 0;
    int high = n-1;
    int ans = INT_MIN;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(arr[mid]>k){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return ans;
}
// Search Insert Position -> Lower Bound of a given number (the index where the given number can be inserted while maintaining a sorted order within the array)
// Floor and Ceil of an element in a sorted array
int main(){
    int n;cout<<"Enter the value of n : ";cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;cout<<"Enter the value of target : ";cin>>k;
    cout<<lower_bound(arr,k)<<endl;
    cout<<upper_bound(arr,k);
}