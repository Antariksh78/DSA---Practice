#include <bits/stdc++.h>
using namespace std;

int stucount(vector<int> arr,int mid){
    int stu=1;int pages=0;
    for(auto it:arr){
        if(pages+it<=mid){
            pages+=it;
        }
        else{
            pages = it;
            stu++;
        }
    }
    return stu;
}

int book_allocate(vector<int> arr,int s){
    int low = arr[0];
    int high = 0;
    for(auto it:arr){
        low = max(low,it);
        high+=it;
    }
    int ans;
    int anss;
    while(low<=high){
        int mid = low+(high-low)/2;
        ans = stucount(arr,mid);
        if(ans>s){
            low=mid+1;
        }
        else{
            anss = mid;
            high = mid-1;
        }
    }
    return anss;
}

int main(){
    int n;cout<<"Enter the value of N : ";cin>>n;
    vector<int> arr(n);cout<<"Enter the elements of the array : ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int d;cout<<"Enter the value of k : ";cin>>d;
    cout<<book_allocate(arr,d);
}