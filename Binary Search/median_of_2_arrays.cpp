#include <bits/stdc++.h>
using namespace std;

double median_of_2_arrays(vector<int> arr1,vector<int> arr2){
    vector<int> ans;
    int n1 = arr1.size();
    int n2 = arr2.size();
    int i=0;int j=0;
    while(i<n1 && j<n2){
        if(arr1[i]<arr2[j]){
            ans.push_back(arr1[i]);
            i++;
        }
        else{
            ans.push_back(arr2[j]);
            j++;
        }
    }
    while(i<n1){
        ans.push_back(arr1[i++]);
    }
    while(j<n2){
        ans.push_back(arr2[j++]);
    }
    int nans = ans.size();
    for(auto it:ans){
        cout<<it;
    }cout<<endl;
    if(nans%2==0){
        return((double)ans[nans/2]+(double)ans[(nans/2)-1])/2.0;
    }
    else{
        return ans[nans/2];
    }
}

double median_of_2_arrays_optimal(vector<int> arr1,vector<int> arr2){
    int i=0;
    int j=0;
    int n1 = arr1.size();
    int n2 = arr2.size();
    int n = n1+n2;
    int ind1 = n/2;
    int ind2 = n/2 -1;
    int ele1 = -1;
    int ele2 = -1;
    int count = 0;
    while(i<n1 && j<n2){
        if(arr1[i]<arr2[j]){
            if(count == ind1) ele1 = arr1[i];
            if(count == ind2) ele2 = arr1[i];
            count++;i++;
        }
        else{
            if(count == ind1) ele1 = arr2[j];
            if(count == ind2) ele2 = arr2[j];
            count++;j++;
        }
    }
    while(i<n1){
        if(count == ind1) ele1 = arr1[i];
        if(count == ind2) ele2 = arr1[i];
        count++;i++;
    }
    while(j<n2){
        if(count == ind1)ele1 = arr2[j];
        if(count == ind2)ele2 = arr2[j];
        count++;j++;
    }
    if(n%2==0){
        return ((double)ele1 + (double)ele2)/2.0;
    }
    else{
        return ele1;
    }
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
    // int d;cout<<"Enter the value of k : ";cin>>d;
    cout<<median_of_2_arrays_optimal(arr,arr2);
}