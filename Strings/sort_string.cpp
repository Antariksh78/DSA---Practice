#include <bits/stdc++.h>
using namespace std;

void sort_string(string &s){
    vector<int> alpha(26,0);
    string ans;
    for(int i=0;i<s.size();i++){
        alpha[s[i]-'a']++;
    }
    for(int i=0;i<26;i++){
        char c = 'a'+i;
        while(alpha[i]!=0){
            ans+=c;
            alpha[i]--;
        }
    }
    s = ans;
}

int main(){
    string s;cin>>s;
    sort_string(s);
    cout<<s;
}