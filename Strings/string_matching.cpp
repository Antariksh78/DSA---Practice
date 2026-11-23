#include <bits/stdc++.h>
using namespace std;

int string_mayching(string s,string s2){
    int n = s.size();
    int m = s2.size();
    if(n<m) return -1;
    for(int i=0;i<=n-m;i++){
        int f = i; int se = 0;
        while(se<m){
            if(s[f]!=s2[se]){
                break;
            }
            else{
                f++;se++;
            }
        }
        if(se==m){
            return f-se;
        }
    }
    return -1;
}

void lps(string s2,vector<int> &lpss,int m){
    int pre = 0; int suf = 1;
    while(suf<m){
        if(s2[pre] == s2[suf]){
            lpss[suf] = pre+1;
            suf++;pre++;
        }
        else{
            if(pre == 0){
                lpss[suf] = 0;
                suf++;
            }
            else{
                pre = lpss[pre-1];
            }
        }
    }
}

int string_matching(string s,string s2){
    int n = s.size();
    int m = s2.size();
    if(n<m) return -1;
    vector<int> lpss(m,0);
    int first = 0; int second = 0;
    lps(s2,lpss,m);
    while(first<n && second<m){
        if(s[first] == s2[second]){
            first++;second++;
        }
        else{
            if(second == 0){
                first++;
            }
            else{
                second = lpss[second-1];
            }
        }
    }
    if(second=m){
        return first-second;
    }
    return -1;
}

int main(){
    string s;
    cin>>s;
    string s2;
    cin>>s2;
    cout<<string_matching(s,s2);
}