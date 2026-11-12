#include <bits/stdc++.h>
using namespace std;

int row_max_element(vector<vector<int>> arr,int mid){
    int n = arr.size();
    int m = arr[0].size();
    int maxi = -1; int ind = -1;
    for(int i=0;i<n;i++){
        if(arr[i][mid]>maxi){
            maxi = arr[i][mid];
            ind = i;
        }
    }
    return ind;
}

vector<int> peak_element_in_a_2d_array(vector<vector<int>> arr){
    int n = arr.size();
    int m = arr[0].size();
    int low = 0;
    int high = m-1;
    while(low<=high){
        int mid = low + (high-low)/2;
        int left = -1; int right = -1;
        int row = row_max_element(arr,mid);
        if(mid-1>=0) left = arr[row][mid-1];
        if(mid+1<m) right = arr[row][mid+1];
        if(arr[row][mid]>left && arr[row][mid]>right){
            return {row,mid};
        }
        else if(arr[row][mid]<left){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return {-1,-1};
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
    vector<int> ans = peak_element_in_a_2d_array(arr);
    for(auto it:ans){
        cout<<it<<",";
    }
}