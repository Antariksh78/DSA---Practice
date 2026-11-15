#include <bits/stdc++.h>
using namespace std;

void sentence(string s){
    vector<string> ans(10);
    int index = 0;
    int count = 0;
    string temp;
    while(index<s.size()){
        if(s[index] == ' '){
            int pos = temp.back() - '0';
            temp.pop_back();
            ans[pos] = temp;
            temp.clear();
            index++;count++;
        }
        else{
            temp += s[index];
            index++;
        }
    }
    int pos = temp.back() - '0';
    temp.pop_back();
    ans[pos] = temp;
    count++;
    for(int i=1;i<=count;i++){
        cout<<ans[i]<<" ";
    }
}

int main(){
    string s;
    getline(cin,s);
    sentence(s);
}