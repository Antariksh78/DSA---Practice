#include <bits/stdc++.h>
using namespace std;

int floor(vector<int> arr,int k){
    int n = arr.size();
    int low = 0;
    int high = n-1;
    int ans = -1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(arr[mid]<=k){
            ans = mid;
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return ans;
}

int ceil(vector<int> arr,int k){
    int n = arr.size();
    int low = 0;
    int high = n-1;
    int ans = -1;
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
// Search Insert Position -> Lower Bound of a given number (the index where the given number can be inserted while maintaining a sorted order within the array)
// Floor and Ceil of an element in a sorted array
int main(){
    int n;cout<<"Enter the value of n : ";cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;cout<<"Enter the value of target : ";cin>>k;
    cout<<floor(arr,k)<<endl;
    cout<<ceil(arr,k)<<endl;
}