#include <bits/stdc++.h>
using namespace std;

int maxi(vector<int> arr){
    int ans = arr[0];
    for(auto it:arr){
        ans = max(ans,it);
    }
    return ans;
    
}
int mini(vector<int> arr){
    int ans = arr[0];
    for(auto it:arr){
        ans = min(ans,it);
    }
    return ans;
}

int answer(vector<int>arr,int mid,int k){
    int count = 0;
    int ans = 0;
    for(auto it:arr){
        if(it-mid<=0){
            count++;
        }
        else{
            ans+=count/k;
            count=0;
        }
    }
    ans+=count/k;
    return ans;
}

int flower_bouquette(vector<int> arr,int m,int k){
    int n = arr.size();
    if(m*k>n){
        return -1;
    }
    int low = mini(arr);
    int high = maxi(arr);
    int ansi=high; 
    while(low<=high){
        int mid = low+(high-low)/2;
        int ans = answer(arr,mid,k);
        if(ans<m){
            low = mid+1;
        }
        else{
            ansi = mid;
            high = mid-1;
        }
    }
    return ansi;
}

int main(){
    int n;cout<<"Enter the value of N : ";cin>>n;
    vector<int> arr(n);cout<<"Enter the elements of the array : ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;cout<<"Enter the value of k : ";cin>>k;
    int m;cout<<"Enter the value of m : ";cin>>m;
    cout<<flower_bouquette(arr,m,k);
}