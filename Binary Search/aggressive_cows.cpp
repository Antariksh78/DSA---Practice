#include <bits/stdc++.h>
using namespace std;

bool canwe_place(vector<int> arr,int cows,int mid){
    int n = arr.size();
    int c_count = 1;
    int last = arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]-last>=mid){
            c_count++;
            last = arr[i];
        }
        else{
            continue;
        }
    }
    return(c_count>=cows);
}

int aggressive_cows(vector<int> arr,int cows){
    sort(arr.begin(),arr.end());
    int n = arr.size();
    int low = 1;
    int high = arr[n-1]-arr[0];
    int ans = high;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(canwe_place(arr,cows,mid)){
            ans = mid;
            low = mid+1;
        }
        else{
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
    int d;cout<<"Enter the value of k : ";cin>>d;
    cout<<aggressive_cows(arr,d);
}