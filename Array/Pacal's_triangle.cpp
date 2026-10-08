#include <bits/stdc++.h>
using namespace std;

int ncr(int n,int r){
    int ans =1;
    for(int i=0;i<r;i++){
        ans = ans*(n-i);
        ans = ans/(i+1);
    }
    return ans;
}

int pascal_triangle_element(int row,int column){
    return ncr(row-1,column-1);
}

void pascal_triangle_row(int n){
    int ans = 1;
    cout<<ans<<" ";
    for(int i=1;i<n;i++){
        ans = ans*(n-i);
        ans = ans/i;
        cout<<ans<<" ";
    }
}

void pascal_triangle(int n){
    for(int i=1;i<=n;i++){
        pascal_triangle_row(i);
        cout<<endl;
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
    pascal_triangle(n);
}