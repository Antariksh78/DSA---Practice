#include <bits/stdc++.h>
using namespace std;

/* [[1,2,3],
    [4,5,6],
    [7,8,9]] ==> [1,2,3,4,5,6,7,8,9](Hypothetical flattening)
    index conversion = row = i/m;(every row is a multiple of m)
                       column = i%m(we need the residue after the multiple for the index);
    */ 

vector<int> search_in_2d_array(vector<vector<int>> arr,int k){
    if(arr.empty() || arr[0].empty()) return{-1,-1};
    int n = arr.size();
    int m = arr[0].size();
    int low = 0;
    int high = m*n-1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(arr[mid/m][mid%m]<k)low = mid+1;
        else if(arr[mid/m][mid%m]>k)high = mid-1;
        else return {mid/m,mid%m};
    }
    return {-1,-1};
}
vector<int> search_in_2d_array_2(vector<vector<int>> arr,int k){
    int n = arr.size();
    int m = arr[0].size();
    int row = 0; int col = m-1;
    while(row<n && col>=0){
        int ele = arr[row][col];
        if(ele == k) return {row,col};
        else if( ele<k) row++;
        else col--;
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
    int k;cout<<"Enter the value of k : ";cin>>k;
    vector<int> ans = search_in_2d_array_2(arr,k);
    for(auto it:ans){
        cout<<it<<",";
    }
}