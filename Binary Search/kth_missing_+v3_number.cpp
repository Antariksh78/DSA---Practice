#include <bits/stdc++.h>
using namespace std;

// [2,3,4,7,11] k = 5 ans = 9
int kth_positive_number_missing(vector<int> arr,int k){
    int n = arr.size();
    int low = 0;
    int high = n-1;
    while(low<=high){
        int mid = low + (high-low)/2;
        int missing = arr[mid] - (mid+1);
        if(missing<k){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return high + k + 1;
    // [2,3,4,7,11] k=5  [4 5 7 9] k=3
    // [1,2,3,4,5]  ans = arr[high] + extra(k-missing(arr[high]-(high+1)))
    //            => arr[high] + k - arr[high] + high + 1
    //            => high + k + 1;
}

int main(){
    int n;cout<<"Enter the value of N : ";cin>>n;
    vector<int> arr(n);cout<<"Enter the elements of the array : ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int d;cout<<"Enter the value of k : ";cin>>d;
    cout<<kth_positive_number_missing(arr,d);
}