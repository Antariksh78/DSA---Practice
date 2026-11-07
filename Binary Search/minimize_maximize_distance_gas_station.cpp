#include <bits/stdc++.h>
using namespace std;

/*[1,13,17,23]
  [1, ,13,17,23]
*/
int mini_max_distance_gas_station(vector<int> arr,int k){
    int n = arr.size();
    vector<int> howmany(n-1,0);
    for(int i=0;i<k;i++){
        int max_distance = -1; int max_d_ind = -1;
        for(int i=0;i<n-1;i++){
            int diff = arr[i+1]-arr[i];
            int section_length = diff/((int)howmany[i]+1);
            if(section_length>max_distance){
                max_distance = section_length;
                max_d_ind = i;
            }
        }
        howmany[max_d_ind]++;
    }
    int ans = -1;
    for(int i = 0;i<n-1;i++){
        int diff = arr[i+1]-arr[i];
        int section = diff/(howmany[i]+1);
        ans = max(ans,section);
    }
    return ans;
}

int mini_max_gas(vector<int> arr,int k){
    int n = arr.size();
    vector<int> howmany(n-1,0);
    priority_queue<pair<int,int>> pq;
    for(int i=0;i<n-1;i++){
        pq.push({arr[i+1]-arr[i],i});
    }
    for(int i=0;i<k;i++){
        auto tp = pq.top().first;
        int ind = pq.top().second;
        pq.pop();
        howmany[ind]++;
        int diff = arr[ind+1]-arr[ind];
        int section_length = diff/((long)howmany[ind]+1);
        pq.push({section_length,ind});
    }
    return pq.top().first;
}

int count_gas_stations(vector<int>arr,double mid){
    int n = arr.size();
    int count = 0;
    for(int i=0;i<n-1;i++){
        int diff = arr[i+1]-arr[i];
        int inbetween = ceil(diff/mid)-1;
        count+=inbetween;
    }
    return count;
}

double mini_binary(vector<int> arr,int k){
    int n = arr.size();
    int maxi = -1;
    for(int i=0;i<n-1;i++){
        maxi = max(maxi,arr[i+1]-arr[i]);
    }
    double low = 0;
    double high = maxi;
    while(high-low>0.0000001){
        double mid = low+ (high-low)/2;
        if(count_gas_stations(arr,mid)>k){
            low = mid;
        }
        else{
            high = mid;
        }
    }
    return high;
}

int main(){
    int n;cout<<"Enter the value of N : ";cin>>n;
    vector<int> arr(n);cout<<"Enter the elements of the array : ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int d;cout<<"Enter the value of k : ";cin>>d;
    cout<<mini_binary(arr,d);
}