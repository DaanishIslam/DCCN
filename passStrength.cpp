// password checking

#include<bits/stdc++.h>

using namespace std;

void findStrengthOfPass(string s){
    bool upperChar=false;
    bool lowerChar=false;
    bool num=false;
    bool specialChar=false;

    for(int i=0;i<s.size();i++){
        if(isupper(s[i])){
            upperChar=true;
        }
        else if(islower(s[i])){
            lowerChar=true;
        }
        else if(isdigit(s[i])){
            num=true;
        }
        else if(!isalpha(s[i])){
            specialChar=true;
        }
    }

    if((upperChar) && (lowerChar) && (num) && (specialChar) && (s.size()>=6)){
        cout<<"Strong Password\n";
    }
    else if((upperChar && lowerChar && specialChar && s.size()>=6) ||
    (upperChar && lowerChar && num && s.size()>=6)){
        cout<<"Moderate Password\n";
    }
    else{
        cout<<"Weak Password\n";
    }

    return ;
}

int main(){

    cout<<"Enter the password: ";
    string s;
    cin>>s;

    findStrengthOfPass(s);

    return 0;
}