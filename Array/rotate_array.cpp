#include <bits/stdc++.h>
using namespace std;

void Rotate_array(int arr[100][100],int n,int m){
    int array[100][100];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            array[j][n-1-i] = arr[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<array[i][j]<<" ";
        }
        cout<<endl;
    }
}

void Reverse_array_row(int arr[][100],int n,int m){
    for(int i=0;i<n;i++){
        int st = 0;
        int en = m-1;
        while(st<en){
            swap(arr[i][st],arr[i][en]);
            st++;
            en--;
        }
    }
}

void Rotate_array_optimal(int arr[][100],int n,int m){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            swap(arr[i][j],arr[j][i]);
        }
    }
    Reverse_array_row(arr,n,m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int n;
    cout<<"Enter the value of n : ";
    cin>>n;
    int arr[100][100];
    cout<<"Enter the value of array elements : ";
    int m;cout<<"Enter the value of m : ";cin>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    Rotate_array_optimal(arr,n,m);
}