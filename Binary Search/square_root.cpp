#include <bits/stdc++.h>
using namespace std;

int square_root(int n){
    int low = 1;
    int high = n;
    int ans = 1;
    while(low<=high){
        int mid = low+(high-low)/2;
        if(mid*mid<=n){
            ans = mid;
            low = mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return ans;
}

int main(){
    int n;cout<<"Enter the value of N : ";cin>>n;
    // vector<int> arr(n);cout<<"Enter the elements of the array : ";
    // for(int i=0;i<n;i++){
    //     cin>>arr[i];
    // }
    cout<<square_root(n);
}