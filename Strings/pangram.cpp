#include <bits/stdc++.h>
using namespace std;

bool pangram(string s){
    vector<int> alpha(26,0);
    for(int i=0;i<s.size();i++){
        alpha[s[i]-'a']++;
    }
    for(int i=0;i<26;i++){
        if(alpha[i]==0) return false;
    }
    return true;
}

int main(){
    string s;
    getline(cin,s);
    cout<<pangram(s);
}