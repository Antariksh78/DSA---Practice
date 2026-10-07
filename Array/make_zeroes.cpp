#include <bits/stdc++.h>
using namespace std;

void make_Row(int arr[][100],int i,int m){
    for(int j=0;j<m;j++){
        arr[i][j] = -1;
    }
}

void make_Column(int arr[][100],int j,int n){
    for(int i=0;i<n;i++){
        arr[i][j] = -1;
    }
}

void set_matrix_zeroes(int arr[100][100],int n,int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==0){
                make_Column(arr,j,n);
                make_Row(arr,i,m);
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==-1){
                arr[i][j]=0;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

void set_matrix_zeroes_better(int arr[100][100],int n,int m){
    int col[m];
    int row[n];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==0){
                col[j]=1;
                row[i]=1;
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(col[j]==1 || row[i] == 1){
                arr[i][j]=0;
            }
        }
    }
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
    set_matrix_zeroes_better(arr,n,m);
}