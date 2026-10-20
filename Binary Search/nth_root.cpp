#include<bits/stdc++.h>
using namespace std;

int multi(int n,int num){
    int ans=1;
    while(n!=0){
        ans = ans*num;
        n--;
    }
    return ans;
}

int nth_root(int n,int num){
    int low = 1;
    int high = num;
    while(low<=high){
        long long mid = low + (high-low)/2;
        if(multi(n,mid)==num){
            return mid;
        }
        else if(multi(n,mid)>num){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return -1;
}

int main(){
    int n;
    cout<<"Enter the value of n : ";cin>>n;
    int number;
    cout<<"Enter the value of number : ";cin>>number;
    cout<<nth_root(n,number);
}