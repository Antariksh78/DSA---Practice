#include <bits/stdc++.h>
using namespace std;

int upper_bound(vector<int>arr,int k){
    int n = arr.size();
    int low = 0;
    int high = n-1;
    int ans = n;
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

int blackbox(vector<vector<int>> arr,int n,int m,int mid){
    int count = 0;
    for(int i=0;i<n;i++){
        count+= upper_bound(arr[i],mid);
    }
    return count;
}

int median_2d_array(vector<vector<int>> arr){
    int n = arr.size();
    int m = arr[0].size();
    int low = INT_MAX; int high = INT_MIN;
    for(int i=0;i<n;i++){
        low = min(low,arr[i][0]);
        high = max(high,arr[i][m-1]);
    }
    int req = (n*m)/2;
    while(low<=high){
        int mid = low + (high-low)/2;
        int ans = blackbox(arr,n,m,mid);
        if(ans<=req) low = mid+1;
        else high = mid-1;
    }
    return low;
}

int main(){
    int n;cout<<"Enter the value of n : ";cin>>n;
    int m;cout<<"Enter the value of m : ";cin>>m;
    vector<vector<int>> arr(n,vector<int>(m));
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    // int k;cout<<"Enter the value of k : ";cin>>k;
    cout<<median_2d_array(arr);
}