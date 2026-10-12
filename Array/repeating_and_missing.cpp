#include <bits/stdc++.h>
using namespace std;

void repeating_and_not_appearing(vector<int> arr){
    unordered_map<int,int> mpp;
    int n = arr.size();
    int maxi = INT_MIN;
    for(int i=0;i<n;i++){
        mpp[arr[i]]++;
        maxi = max(maxi,arr[i]);
    }
    for(int i=1;i<=maxi;i++){
        if(mpp.find(i) == mpp.end()){
            cout<<"The number not appearing even once is "<<i<<endl;
        }
        else if(mpp[i]==2){
            cout<<"The number appearing twice is "<<i;
        }
        else{
            continue;
        }
    }
}

vector<int> missing_and_repeating(vector<int> arr){
    int n = arr.size();
    int sum1 = ((n*(n+1))/2);
    int sums1 = ((n*(n+1)*(2*n+1))/6);
    int sum2 = 0;
    int sums2 = 0;
    for(int i=0;i<n;i++){
        sum2 +=arr[i];
        sums2 += arr[i]*arr[i];
    }
    int value1 = sum2-sum1;
    int value2 = sums2-sums1;
    value2 = value2/value1;
    int x = (value1+value2)/2;
    int y = x-value1;
    return {x,y};
}

int main(){
    int n;
    cout<<"Enter the value of n : ";
    cin>>n;
    vector<int> arr1;


    repeating_and_not_appearing(arr1);
}