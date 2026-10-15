#include <bits/stdc++.h>
using namespace std;

int number_of_rotation(vector<int> arr){
    int n = arr.size();
    int low = 0;
    int high = n-1;
    int ans = INT_MAX;
    int index =  -1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(arr[low] == arr[mid] && arr[mid]==arr[high]){
            low++;
            high--;
            continue;
        }
        if(arr[low]<=arr[high]){
            if(arr[low]<ans){
                ans = arr[low];
                index = low;
            }
        }

        if(arr[low]<=arr[mid]){
            if(arr[low]<ans){
                ans = arr[low];
                index = low;
            }
            low = mid+1;
        }
        else{
            if(arr[mid]<ans){
                ans = min(ans,arr[mid]);
                index = mid;
            }
            high = mid-1;

        }

    }
    return index;
}


int main(){
    int n;cout<<"Enter the value of N : ";cin>>n;
    vector<int> arr(n);cout<<"Enter the elements of the array : ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    // int k;cout<<"Enter the value of K : ";cin>>k;
    cout<<number_of_rotation(arr);
}