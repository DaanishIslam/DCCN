// parity check

#include<bits/stdc++.h>
using namespace std;

void formEvenParity(string s){
    int count1 = 0;

    for(int i = 0 ; i < s.size() ; i++)
        if(s[i] == '1') count1++;

    if(count1 & 1) s += "1";
    else s += "0";

    cout << "The parity bit code : ";
    cout << s << "\n";

    return ;
}

int main(){

    cout << "\nEnter the data bit : ";
    string s;
    cin >> s;

    formEvenParity(s);

    return 0;
}
