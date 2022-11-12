// parity check

#include<bits/stdc++.h>

using namespace std;

void formEvenParity(string s){
    int countO=0;
    for(auto it:s){
        if(it=='1'){
            countO++;
        }
    }

    if(countO&1){
        s+="1";
    }
    else{
        s+="0";
    }

    cout<<"The parity bit code : ";
    cout<<s<<"\n";

    return ;
}

int main(){
    cout<<"\nEnter the data bit : ";
    string s;
    cin>>s;

    formEvenParity(s);

    return 0;
}