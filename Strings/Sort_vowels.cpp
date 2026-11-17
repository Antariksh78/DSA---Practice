#include <bits/stdc++.h>
using namespace std;

void sort_vowels(string &s){
    vector<int> l(26,0);
    vector<int> u(26,0);
    string ans;
    for(int i=0;i<s.size();i++){
        if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
            l[s[i]-'a']++;
            s[i]='*';
        }
        else if(s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'){
            u[s[i]-'A']++;
            s[i] = '*';
        }
    }
    for(int i=0;i<26;i++){
        char c = 'A'+i;
        while(u[i]){
            ans+=c;
            u[i]--;
        }
    }
        for(int i=0;i<26;i++){
        char c = 'a'+i;
        while(l[i]){
            ans+=c;
            l[i]--;
        }
    }
    int index=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='*'){
            s[i] = ans[index];
            index++;
        }
    }
}

int main(){
    string s;
    cin>>s;
    sort_vowels(s);
    cout<<s;
}