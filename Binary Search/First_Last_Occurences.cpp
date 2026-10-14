#include <bits/stdc++.h>
using namespace std;

//Method 1 - use lower bound and upper bound as the first occurence is lower bound and the last occurence is upper bound -1;

//Method 2 -
int first_occurence(vector<int> arr,int k){
    int focc = -1;
    int n = arr.size();
    int low = 0;
    int high = n-1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(arr[mid]>k){
            high = mid-1;
        }
        else if(arr[mid]<k){
            low = mid+1;
        }
        else{
            focc = mid;
            high = mid-1;
        }
    }
    return focc;
}

int last_occurence(vector<int> arr,int k){
    int locc = -1;
    int n = arr.size();
    int low = 0;
    int high = n-1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(arr[mid]>k){
            high = mid-1;
        }
        else if(arr[mid]<k){
            low = mid+1;
        }
        else{
            locc = mid;
            low= mid+1;
        }
    }
    return locc;
}

int main(){
    int n;cout<<"Enter the value of n : ";cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;cout<<"Enter the value of target : ";cin>>k;
    cout<<first_occurence(arr,k);
    cout<<last_occurence(arr,k);
}