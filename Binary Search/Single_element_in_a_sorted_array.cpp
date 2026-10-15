#include <bits/stdc++.h>
using namespace std;
// 0 1 2 3 4 5 6 7 8 9 10
//[1,1,2,2,3,3,4,5,5,6,6] 

int single_element(vector<int> arr){
    int n = arr.size();
    int low = 1;
    int high = n-2;
    if(n==1)return arr[0];
    if(arr[0]!=arr[1])return arr[0];
    if(arr[n-1]!=arr[n-2])return arr[n-1];
    while(low<=high){
        int mid = low + (high-mid)/2;
        if(arr[mid]!=arr[mid-1] && arr[mid]!=arr[mid+1])return arr[mid];
        if((mid%2==0 && arr[mid+1]==arr[mid])||( mid %2==1 && arr[mid-1]==arr[mid]))low = mid+1;
        else{
            high = mid-1;
        }
    }
    return -1;
}

int main(){
    int n;cout<<"Enter the value of N : ";cin>>n;
    vector<int> arr(n);cout<<"Enter the elements of the array : ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    // int k;cout<<"Enter the value of K : ";cin>>k;
    cout<<single_element(arr);
}