#include <bits/stdc++.h>
using namespace std;

string defanging2(string s){
    int index = 0;
    string ans;
    while(index<s.size()){
        if(s[index]=='.'){
            ans+="[.]";
        } 
        else{
            ans+=s[index];
        }
        index++;
    }
    return ans;
}

int main(){
    string s;cin>>s;
    cout<<defanging2(s);
    

}