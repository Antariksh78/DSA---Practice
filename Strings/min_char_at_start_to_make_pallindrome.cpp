#include <bits/stdc++.h>
using namespace std;

bool is_pall(string s,int m){
    int i = 0; int j = m;
    while(i<=j){
         if(s[i] != s[j]){
            return false;
        } 
        i++;j--;
    }
    return true;
}

int min_char_at_atart(string s){
    int n = s.size();
    string ans="";
    int j = n-1;
    while(j>=0){
        if(is_pall(s,j)){
            return ans.size();
        }
        else{
            ans += s[j];
            j--;
        }
    }
    return ans.size();
}

int longest_prefix_pallindrome(string s){
    int max = 1;
    int n = s.size();int j = 1;
    while(j<n){
        if(is_pall(s,j)){
            max = j+1;
        }
        j++;
    }
    return n-max;
}

int main(){
    string s;cin>>s;
    cout<<longest_prefix_pallindrome(s);
}