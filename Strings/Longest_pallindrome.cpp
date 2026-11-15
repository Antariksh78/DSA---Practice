#include <bits/stdc++.h>
using namespace std;

int longest_pallindrome(string s){
    int count = 0;
    bool is_odd = false;
    unordered_map<char,int> mpp;
    int n = s.size();
    for(int i=0;i<n;i++){
        mpp[s[i]]++;
    }
    for(const auto& pair:mpp){
        if(pair.second%2==0){
            count+=pair.second;
        }
        else{
            count+= pair.second-1;
            is_odd = true;
        }
    }
    if(is_odd){
        count+=1;
    }
    return count;
}

int main(){
    string s;
    cin>>s;
    cout<<longest_pallindrome(s);
}