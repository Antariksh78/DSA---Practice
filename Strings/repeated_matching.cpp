#include <bits/stdc++.h>
using namespace std;

void lpss(vector<int>& lps,const string& s){
    int pre = 0; int suf = 1;
    while(suf<s.size()){
        if(s[pre] == s[suf]){
            lps[suf] = pre+1;
            pre++;suf++;
        }
        else{
            if(pre == 0){
                lps[suf] = 0;
                suf++;
            }
            else{
                pre = lps[pre-1];
            }
        }
    }
}

bool pattern_matching(string s, string p){
    int m = p.size();
    vector<int> lps(m,0);
    lpss(lps,p);
    int n = s.size();
    int first = 0; int second = 0;
    while(first<n && second<m){
        if(s[first] == p[second]){
            first++;second++;
        }
        else{
            if(second == 0){
                first++;
            }
            else{
                second = lps[second-1];
            }
        }
    }
    if(second==m){
        return true;
    }
    return false;
}

int repeated_string_matching(string s,string p){
    if(s==p) return 1;
    int repetition = 1;
    string temp = s;
    while(temp.size()<p.size()){
        temp+=s;repetition++;
    }
    if(pattern_matching(temp,p)) return repetition;
    if(pattern_matching(temp+s,p)) return repetition+1;
    return -1;
    
}

int main(){
    string s;cin>>s;
    string p;cin>>p;
    cout<<repeated_string_matching(s,p);
}