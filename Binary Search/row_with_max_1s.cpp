#include <bits/stdc++.h>
using namespace std;

int lower_bound(vector<int> arr,int k){
    int n = arr.size();
    int low = 0;
    int high = n-1;
    int ans = n;
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

int row_max_1s(vector<vector<int>> arr,int r,int c){
    int ans = -1;
    int anss = -1;
    for(int i = 0;i<r;i++){
        int count = c-lower_bound(arr[i],1)+1;
        if(count>anss){
            anss = count;
            ans = i;
        }
    }
    return ans;
}

int main(){
    int n;cout<<"Enter the value of n : ";cin>>n;
    int m;cout<<"Enter the value of m : ";cin>>m;
    vector<vector<int>> arr(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    cout<<row_max_1s(arr,n,m);
}