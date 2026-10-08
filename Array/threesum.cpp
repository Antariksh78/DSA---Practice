#include <bits/stdc++.h>
using namespace std;

void threesum_better(int arr[],int n){
    set<vector<int>> stt;
    for(int i=0;i<n;i++){
        set<int> st;
        for(int j=i+1;j<n;j++){
            int element = -(arr[i]+arr[j]);
            if(st.find(element)!=st.end()){
                vector<int> ans = {arr[i],arr[j],element};
                sort(ans.begin(),ans.end());
                stt.insert(ans);
            }
            else{
                st.insert(arr[j]);
            }
        }
    }
    for(auto it:stt){
        for(auto x:it){
            cout<<x<<" ";
        }
        cout<<endl;
    }

}

//Sorted array
void three_sum_optimal(int arr[],int n){
    set<vector<int>> stt;
    for(int i=0;i<n;i++){
        if(i>0 && arr[i]==arr[i-1])continue;
        int j=i+1;
        int k=n-1;
        while(j<k){
            int sum = arr[i]+arr[j]+arr[k];
            if(sum<0){
                j++;
            }
            else if(sum>0){
                k--;
            }
            else{
                vector<int> ans = {arr[i],arr[j],arr[k]};
                stt.insert(ans);
                j++;
                k--;
                while(arr[j]==arr[j-1])j++;
                while(arr[k]==arr[k+1])k--;
            }
        }
    }
    for(auto it:stt){
        for(auto x:it){
            cout<<x<<" ";
        }
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
    three_sum_optimal(arr,n);
}