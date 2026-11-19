#include <bits/stdc++.h>
using namespace std;

int roman(char c){
    if(c=='I') return 1;
    else if(c=='V') return 5;
    else if(c=='X') return 10;
    else if(c=='L') return 50;
    else if(c=='C') return 100;
    else if(c=='D') return 500;
    else return 1000;
}

int roman_to_in(string s){
    int ans = 0; int index = 0;
    while(index<s.size()-1){
        if(roman(s[index])<roman(s[index+1])){
            ans+=-roman(s[index]);
            index++;
            }
        else{
        ans+=roman(s[index]);
        index++;
    }
    }
    ans+=roman(s[s.size()-1]);
    return ans;
}

string intToRoman(int num) {
        string roman;
        int rem = num%10;
        num = num/10;
        if(rem==1)roman+="I";
        else if(rem==2)roman+="II";
        else if(rem==3)roman+="III";
        else if(rem==4)roman+="IV";
        else if(rem==5)roman+="V";
        else if(rem==6)roman+="VI";
        else if(rem==7)roman+="VII";
        else if(rem==8)roman+="VIII";
        else if(rem==9)roman+="IX";
        rem = num%10;
        num = num/10;
        if(rem == 1) roman="X"+roman;
        else if(rem==2)roman="XX"+roman;
        else if(rem==3)roman="XXX"+roman;
        else if(rem==4)roman="XL"+roman;
        else if(rem==5)roman="L"+roman;
        else if(rem==6)roman="LX"+roman;
        else if(rem==7)roman="LXX"+roman;
        else if(rem==8)roman="LXXX"+roman;
        else if(rem==9)roman="XC"+roman;
        rem = num%10;
        num = num/10;
        if(rem == 1) roman="C"+roman;
        else if(rem == 2)roman="CC"+roman;
        else if(rem == 3)roman="CCC"+roman;
        else if(rem == 4)roman="CD"+roman;
        else if(rem == 5)roman="D"+roman;
        else if(rem == 6)roman="DC"+roman;
        else if(rem == 7)roman="DCC"+roman;
        else if(rem == 8)roman="DCCC"+roman;
        else if(rem == 9)roman="CM"+roman;
        rem = num%10;
        num = num/10;
        if(rem == 1)roman="M"+roman;
        else if(rem == 2)roman="MM"+roman;
        else if(rem == 3)roman="MMM"+roman;
        return roman;
    }

int main(){
    string s;
    cin>>s;
    cout<<roman_to_in(s);
}