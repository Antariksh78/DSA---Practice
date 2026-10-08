#include <bits/stdc++.h>
using namespace std;

void merge_overlapping_interval(vector<vector<int>> arr){
    int n= arr.size();
    vector<vector<int>> ans;
    for(int i=0;i<n;i++){
        if(ans.empty() || arr[i][0] > ans.back()[1]){
            ans.push_back(arr[i]);
        }
        else{
            ans.back()[1] = max(ans.back()[1],arr[i][1]);
        }
    }
    for(auto it:ans){
        for(auto x:it){
            cout<<x<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int n;
    cout<<"Enter the value of n : ";
    cin>>n;
    int m;cout<<"Enter the value of m ";cin>>m;
    vector<vector<int>> arr(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    merge_overlapping_interval(arr);
    
}