// bit stuffing

#include<bits/stdc++.h>

using namespace std;

void bitStuffing(string s){
    string ans="";
    int countO=0;
    int countZ=0;
    int n=s.size();

    for(int i=0;i<n;i++){
        ans=ans+s[i];

        if(s[i]=='1'){
            countO++;
        }
        else{
            if(countZ>0){
                countZ=0;
            }
            countZ++;
            countO=0;
        }

        if(countO==5  && countZ>0){
            ans=ans+"0";
        }

    }

    cout<<"\nThe stuffed code is : ";
    cout<<ans<<"\n";
}

int main(){
    cout<<"Enter the data bits : ";
    string s;
    cin>>s;

    bitStuffing(s);

    return 0;
}
