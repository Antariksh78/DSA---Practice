#include <bits/stdc++.h>
using namespace std;

void spiral_matrix(int arr[][100],int n,int m){
    int left = 0;
    int right = m-1;
    int top = 0;
    int bottom = n-1;
    vector<int> array;
    while(top<=bottom && left<=right){
        for(int i=left;i<=right;i++){
            array.push_back(arr[top][i]);
        }
        top++;
        for(int i=top;i<=bottom;i++){
            array.push_back(arr[i][right]);
        }
        right--;
        if(top<=bottom){
            for(int i=right;i>=left;i--){
                array.push_back(arr[bottom][i]);
            }
            bottom--;
        }
        if(left<=right){
            for(int i=bottom;i>=top;i--){
                array.push_back(arr[i][left]);
            }
            left++;
        }
    }
    for(auto it:array){
        cout<<it<<" ";
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
    spiral_matrix(arr,n,m);
}