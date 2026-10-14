#include <bits/stdc++.h>
using namespace std;

/*
[7,8,9,1,2,3,4,5,6] k = 9 
check if the left is sorted or is the right sorted
mid = 4 arr[mid] = 2 if arr[mid] == k return 
else if(arr[low]<=arr[mid])
*/

int searching_in_rotated_array(vector<int> arr,int k){
    int n = arr.size();
    int low = 0;
    int high = n-1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(arr[low] == arr[mid] && arr[mid] == arr[high]){
            low = low+1;
            high = high-1;
        }
        if(arr[mid]==k)return mid;
        else if(arr[low]<=arr[mid]){
            if(arr[low]<=k && arr[mid]>=k)high = mid-1;
            else low = mid+1;
        }
        else{
            if(arr[mid]<=k && arr[high]>=k)low = mid+1;
            else high = mid-1;
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
    cout<<searching_in_rotated_array(arr,k);
}