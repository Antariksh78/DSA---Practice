#include <bits/stdc++.h>
using namespace std;

int smallest_distinct_window(string s){
    int f =0;
    int se = 0;int len = s.size();
    vector<int>count(256,0);
    set<int>st;
    int countt=0;
    while(se<s.size()){
        if(count[s[se]]==0){
            countt++;
            count[s[se]]++;
            se++;
        }
    }
    for(int i=0;i<256;i++){
        count[i]=0;
    }
    se=0;
    while(se<s.size()){
        while(countt && se<s.size()){
            if(count[s[se]]==0){
                countt--;
                count[s[se]]++;
            }
            se++;
            len = min(len,se-f+1);
        }   while(countt!=1){
                len = min(len,se-f+1);
                count[s[f]]--;
                if(count[s[f]]==0)countt++;
                f++;
        }
    }
    return len;
}

int main(){
    string s;
    cin>>s;
    cout<<smallest_distinct_window(s);
}