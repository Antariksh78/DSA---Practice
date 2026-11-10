#include <bits/stdc++.h>
using namespace std;

int kth_element_of_two_arrays(vector<int> arr1,vector<int> arr2,int k){
    int n1 = arr1.size();
    int n2 = arr2.size();
    int count = 0;
    int i = 0;
    int j = 0;
    int ele = -1;
    while(i<n1 && j<n2){
        if(arr1[i]<arr2[j]){
            if(count == k-1){
                ele = arr1[i];
                break;
            }
            i++;count++; 
        }
        else{
            if(count == k-1){ 
                ele = arr2[j];
                break;
            }
            j++;count++;
        }
    }
    while(i<n1){
        if(count == k-1){ 
            ele = arr1[i];
            break;
        }
        i++;count++;
    }
    while(j<n2){
        if(count == k-1){ 
            ele = arr2[j];
            break;
        }
        j++;count++;
    }
    return ele;
}

int kth_ele_BS(vector<int> arr1,vector<int> arr2,int k){
    int n1 = arr1.size();
    int n2 = arr2.size();
    if(n1>n2) return kth_ele_BS(arr2,arr1,k);
    int n = n1+n2;
    int left = k;
    int low = max(0,k-n2);
    int high = min(n1,k);
    while(low<=high){
        int mid1 = low+(high-low)/2;
        int mid2 = left-mid1;
        int l1 = INT_MIN; int l2 = INT_MIN;
        int r1 = INT_MAX; int r2 = INT_MAX;
        if(mid1-1>=0) l1 = arr1[mid1-1];
        if(mid2-1>=0) l2 = arr2[mid2-1];
        if(mid1<n1) r1 = arr1[mid1];
        if(mid2<n2) r2 = arr2[mid2];
        if(l1<=r2 && l2<=r1){
            return max(l1,l2);
        }
        else if(l1>r2){
            high = mid1-1;
        }
        else{
            low = mid1+1;
        }
    }
    return -1;
}

int main(){
    int n;cout<<"Enter the value of N : ";cin>>n;
    vector<int> arr(n);cout<<"Enter the elements of the array : ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int n2;cout<<"Enter the value of N2 : ";cin>>n2;
    vector<int> arr2(n2);cout<<"Enter the values of array2: ";
    for(int i=0;i<n2;i++){
        cin>>arr2[i];
    }
    int d;cout<<"Enter the value of k : ";cin>>d;
    cout<<kth_ele_BS(arr,arr2,d);
}