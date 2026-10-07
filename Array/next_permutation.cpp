#include <bits/stdc++.h>
using namespace std;

void Reverse_Array(int arr[],int low,int high){
    int i=low;
    int j=high;
    while(i<j){
        swap(arr[i],arr[j]);
        i++;
        j--;
    }
}

void next_permutation_code(int arr[],int n){
    int index = -1;
    for(int i=n-2;i>=0;i--){
        if(arr[i]<arr[i+1]){
            index = i;
            break;
        }
    }
    if(index==-1){
        Reverse_Array(arr,0,n-1);
        return;
    }
    for(int i=n-1;i>=0;i--){
        if(arr[i]>arr[index]){
            swap(arr[i],arr[index]);
            break;
        }
    }
    Reverse_Array(arr,index+1,n-1);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int n;
    cout<<"Enter the value of n : ";
    cin>>n;
    int arr[100];
    cout<<"Enter the value of array elements : ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    next_permutation_code(arr,n);

}