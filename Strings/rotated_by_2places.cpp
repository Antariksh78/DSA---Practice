#include <bits/stdc++.h>
using namespace std;

void anticlockwise(string &aclck){
    string ans;
    for(int i=0;i<aclck.size();i++){
        ans+= aclck[(i+2)%aclck.size()];
    }
    aclck = ans;
}
//[s,t,r,i,n,g]
//[0,1,2,3,4,5]
void clockwise(string &clck){
    string ans;
    for(int i=0;i<clck.size();i++){
        ans+= clck[(clck.size()-2+i)%clck.size()]; 
    }
    clck = ans;
}

bool check_rotated(string str1,string str2){
    if(str1.size()!=str2.size()) return 0;
    string clck = str1; string aclck = str1;
    clockwise(clck);
    anticlockwise(aclck);
    if(clck == str2){
        return 1;
    }
    if(aclck == str2){
        return 1;
    }
    return 0;
}

int main(){
    string s1;cin>>s1;
    string s2;cin>>s2;
    cout<<check_rotated(s1,s2);
}