#include <bits/stdc++.h>
using namespace std;

void four_sum_better(int arr[],int n){
    set<vector<int>> stt;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            set<int> st;
            for(int k=j+1;k<n;k++){
                int sum = arr[i]+arr[j]+arr[k];
                int fourth = -sum;
                if(st.find(fourth)!=st.end()){
                    vector<int> ans = {arr[i],arr[j],arr[k],fourth};
                    sort(ans.begin(),ans.end());
                    stt.insert(ans);
                }
                else{
                    st.insert(arr[k]);
                }
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

//Sorted Array
void four_sum_optimal(int arr[],int n){
    set<vector<int>> stt;
    for(int i=0;i<n;i++){
        if(i>0 && arr[i]==arr[i-1])continue;
        for(int j=i+1;j<n;j++){
            if(j>i+1 && arr[j]==arr[j-1])continue;
            int k = j+1;
            int l = n-1;
            while(k<l){
                int sum = arr[i]+arr[j]+arr[k]+arr[l];
                if(sum<0){
                    k++;
                }
                else if(sum>0){
                    l--;
                }
                else{
                    vector<int> ans = {arr[i],arr[j],arr[k],arr[l]};
                    stt.insert(ans);
                    k++;l--;
                    while(arr[k]==arr[k-1])k++;
                    while(arr[l]==arr[l+1])l--;
                }
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
    four_sum_optimal(arr,n);
}