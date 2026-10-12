#include <bits/stdc++.h>
using namespace std;

int Merge_inversion(int arr[],int low,int mid,int high){
    int count=0;
    vector<int> array;
    int left = low;
    int right = mid+1;
    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            array.push_back((arr[left]));
            left++;
        }
        else{
            array.push_back(arr[right]);
            right++;
            count +=(mid-left+1); 
        }
    }
    while(left<=mid){
        array.push_back(arr[left]);
        left++;
    }
    while(right<=high){
        array.push_back(arr[right]);
        right++;
    }
    for(int i=low;i<=high;i++){
        arr[i] = array[i-low];
    }
    return count;

}

int Merge_Sort_inversion(int arr[],int low,int high){
    int countt = 0;
    if(low == high) return countt;
    int mid = (low+high)/2;

    countt+= Merge_Sort_inversion(arr,low,mid);
    countt+= Merge_Sort_inversion(arr,mid+1,high);
    countt+= Merge_inversion(arr,low,mid,high);
    return countt;
}

int main(){
    int n;
    cout<<"Enter the value of n : ";
    cin>>n;
    int n1;
    cout<<"Enter the value of n2: ";
    cin>>n1;
    int arr[100];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }


    cout<<Merge_Sort_inversion(arr,0,n-1);
}