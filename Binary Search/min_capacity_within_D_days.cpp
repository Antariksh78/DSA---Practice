#include <bits/stdc++.h>
using namespace std;

int days(vector<int> arr,int mid){
    int day =1;
    int sum = 0;
    for(auto it:arr){
        if(sum+it>mid){
            day++;
            sum=0;
        }
        sum+=it;
    }
    return day;
}

int capacity(vector<int> arr,int d){
    int low = arr[0];
    int high = 0;
    for(auto it:arr){
        low = max(low,it);
        high+=it;
    }
    int dayss = high;
    while(low<=high){
        int mid = low +(high-low)/2;
        if(days(arr,mid)>d){
            low = mid+1;
        }
        else{
            dayss = mid;
            high = mid-1;
        }
    }
    return dayss;
}

int main(){
    int n;cout<<"Enter the value of N : ";cin>>n;
    vector<int> arr(n);cout<<"Enter the elements of the array : ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int d;cout<<"Enter the value of threshold : ";cin>>d;
    cout<<capacity(arr,d);
}