#include <bits/stdc++.h>
using namespace std;

string prefix(int len,string s){
    string ans;int i = 0;
    while(len){
        ans+=s[i];
        i++;len--;
    }
    return ans;
}

string suffix(int len,string s){
    string ans;int i = s.size()-1;
    while(len){
        ans=s[i]+ans;
        i--;len--;
    }
    return ans;
}

int longest_prefix_suffix(string s){
    int n = s.size();
    int len = 1;int ans=0;
    while(len<n){
        if(prefix(len,s) == suffix(len,s)){
            ans = len;
        }
        len++;
    }
    return ans;
}
int lps(string s){
    int n = s.size();
    vector<int> lps(n,0);
    int pre = 0; int suf = 1;
    while(suf<n){
            if(s[pre] == s[suf]){
                lps[suf] = pre+1;
                pre++;suf++;
            }
            else {
                if(pre == 0){
                    lps[suf] = 0;
                    suf++;
                }
                else{
                    pre = lps[pre-1];
                }
            }
    }
    return lps[n-1];
}

int main(){
    string s;
    cin>>s;
    cout<<longest_prefix_suffix(s);
}