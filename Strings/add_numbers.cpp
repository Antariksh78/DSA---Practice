#include <bits/stdc++.h>
using namespace std;

string add_string(string s1,string s2){
    string ans;
    int temp;
    temp = 0;
    int carry =0; int value =0;
    int i=s1.size()-1, j=s2.size()-1;
    while(i>=0 && j>=0){
        temp = (s1[i]-'0') + s2[j]-'0'+ carry;
        carry = temp/10;
        value = temp%10;
        ans.push_back(value+'0');
        i--;j--;
    }
    while(i>=0){
        temp = s1[i]-'0'+carry;
        carry = temp/10;
        value = temp%10;
        ans.push_back(value+'0');
        i--;
    }
    while(j>=0){
        temp = s2[j]-'0'+carry;
        carry = temp/10;
        value = temp%10;
        ans.push_back(value+'0');
        j--;
    }
    if(carry) ans.push_back(carry+'0');
    reverse(ans.begin(),ans.end());
    return ans;
}

int main(){
    string s1;cin>>s1;
    string s2;cin>>s2;
    cout<<add_string(s1,s2);
}