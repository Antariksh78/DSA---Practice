#include <bits/stdc++.h>
using namespace std;


void rearrange_by_sign(int arr[],int n){
    int pos=0;
    int neg=1;
    int array[100];
    for(int i=0;i<n;i++){
        if(arr[i]>=0){
            array[pos] = arr[i];
            pos+=2;
        }
        else{
            array[neg] = arr[i];
            neg+=2;
        }
    }
    for(int i=0;i<n;i++){
        cout<<array[i]<<" ";
    }
}

void rearrange_by_sign_unequal(int arr[],int n){
    vector<int> pos;
    vector<int> neg;
    for(int i=0;i<n;i++){
        if(arr[i]>=0){
            pos.push_back(arr[i]);
        }
        else{
            neg.push_back(arr[i]);
        }
    }
    if(pos.size()>neg.size()){
        for(int i=0;i<neg.size();i++){
            arr[2*i] = pos[i];
            arr[2*i+1] = neg[i];
        }
        int index = 2*neg.size();
        for(int i=neg.size();i<pos.size();i++){
            arr[index] = pos[i];
            index++;
        }
    }
    else{
        for(int i=0;i<pos.size();i++){
            arr[2*i] = pos[i];
            arr[2*i+1] = neg[i];
        }
        int index = 2*pos.size();
        for(int i=pos.size();i<neg.size();i++){
            arr[index] = neg[i];
            index++;
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

}

int main(){
    int n;
    cout<<"Enter the value of n : ";cin>>n;
    int arr[100];
    cout<<"Enter the value of array elements : ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    rearrange_by_sign_unequal(arr,n);   
}