#include <bits/stdc++.h>
using namespace std;

int maximum_product_array(vector<int> arr){
    int n=arr.size();
    int rprod = 1;
    int lprod = 1;
    int maxi = 1;
    for(int i=0;i<n;i++){
        if(rprod == 0)rprod = 1;
        if(lprod == 0)lprod = 1;
        rprod *= arr[i];
        lprod *= arr[n-i-1];
        maxi = max(maxi,max(lprod,rprod));
    }
    return maxi;
}

int main(){
    int n;
    cout<<"Enter the value of n : ";
    cin>>n;
    int n1;
    cout<<"Enter the value of n2: ";
    cin>>n1;
    vector<int> arr1(n);
    for(int i=0;i<n;i++){
        cin>>arr1[i];
    }



    maximum_product_array(arr1);
}