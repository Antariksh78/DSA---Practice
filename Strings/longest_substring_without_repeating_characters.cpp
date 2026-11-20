#include <bits/stdc++.h>
using namespace std;

int longest_substring_without_repeating_characters(string s){
    int len =0;vector<bool>count(256,0);
    int f = 0 ;int se = 0;
    while(se<s.size()){
        while(count[s[se]]){
            count[s[f]]=0;
            f++;
        }
        count[s[se]]=1;
        len = max(len,se-f+1);
        se++;
    }
    return len;
}

int main(){
    string s;
    getline(cin,s);
    cout<<longest_substring_without_repeating_characters(s);

}