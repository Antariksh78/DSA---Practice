#include <bits/stdc++.h>
using namespace std;

void Merge(int arr[],int low,int mid,int high){
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

}

void Merge_Sort(int arr[],int low,int high){
    if(low == high) return;
    int mid = (low+high)/2;

    Merge_Sort(arr,low,mid);
    Merge_Sort(arr,mid+1,high);
    Merge(arr,low,mid,high);
}

int longest_consecutive_sequence(int arr[],int n){
    Merge_Sort(arr,0,n-1);
    int longest =0;
    int count =1;
    int lastsmall = INT_MIN; 
    for(int i=0;i<n;i++){
        if(arr[i]-1 == lastsmall){
            count++;
            lastsmall = arr[i];
        }
        else{
            count = 1;
            lastsmall = arr[i];
        }
        longest = max(longest,count);
    }
    return longest;
}

int longest_consecutive_sequence_optimal(int arr[],int n){
    int longest = 1;
    unordered_set<int> stt;
    for(int i=0;i<n;i++){
        stt.insert(arr[i]);
    }
    for(auto it:stt){
        if(stt.find(it-1) == stt.end()){
            int count = 1;
            int x=it;
            while(stt.find(x+1) != stt.end()){
                count++;
                x++;
            }
            longest = max(longest,count);
        }
    }
    return longest;
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
    longest_consecutive_sequence(arr,n);
}