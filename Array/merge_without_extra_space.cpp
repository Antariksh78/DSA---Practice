#include <bits/stdc++.h>
using namespace std;

void merge_without_extra_space(vector<int> arr1,vector<int> arr2){
    int n = arr1.size();
    int m  = arr2.size();
    int i=n-1;
    int j=0;
    while(i>=0 && j<m){
        if(arr1[i]>arr2[j]){
            swap(arr1[i],arr2[j]);
            i--;j++;
        }
        else{
            break;
        }
    }
    sort(arr1.begin(),arr1.end());
    sort(arr2.begin(),arr2.end());

    for(auto it:arr1){
        cout<<it<<" ";
    }
    cout<<endl;
    for(auto it:arr2){
        cout<<it<<" ";
    }
}

int main(){
    int n;
    cout<<"Enter the value of n : ";
    cin>>n;
    int n1;
    cout<<"Enter the value of n2: ";
    cin>>n1;
    vector<int> arr1;
    vector<int> arr2;


    merge_without_extra_space(arr1,arr2);
}