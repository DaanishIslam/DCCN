// implement crc

#include<bits/stdc++.h>

using namespace std;

string findXor(string a,string b){
    string ans="";

    for(int i=0;i<a.size();i++){
        if(a[i]==b[i]) ans+="0";
        
        else ans+="1";
    }

    return ans.substr(1);
}

string divide(string s,string g){
    int n=g.size();
    string temp=s.substr(0,n);
    int i=n;

    while(i<s.size()){
        if(temp[0]=='1') temp=findXor(temp,g);
        
        else{
            string t = "";
            for(int i=0;i<n;i++) t+="0";

            temp=findXor(temp,t);
        }

        temp=temp+s[i];
        i++;
    }

    if(temp[0]=='1') temp=findXor(temp,g);
    
    else{
        string t = "";
        for(int i=0;i<n;i++) t+="0";
        
        temp=findXor(temp,t);
    }

   return temp;
}

void generateCode(string s,string g){
    int n=s.size(), m=g.size();
    int x=m-1;
    string ans = s;

    while(x--){
        s+="0";
    }

    string rem = divide(s,g);
    ans=ans+rem;

    cout<<"\nThe encoded data is : ";
    cout<<ans<<" \n";

}

void checkCode(string s,string g){
    string rem = divide(s,g);

    int count=0;
    for(int i=0;i<rem.size();i++){
        if(rem[i]=='0') count++;
    }

    if(count==rem.size()) cout<<"\nNo Error";
    else cout<<"\nError Found";
    
    return ;
}


int main(){
    cout<<"\nEnter the data : ";
    string s;
    cin>>s;

    cout<<"\nEnter the generator : ";
    string g;
    cin>>g;

    cout<<"\nOption : ";
    cout<<"\n1.Generate CRC CODE";
    cout<<"\n2.Check Valid Code";

    int n;
    cout<<"\nEnter Your Choice : ";
    cin>>n;

    switch (n){
    case 1:
        generateCode(s,g);
        break;
    case 2:
        checkCode(s,g);
        break;
    
    default:
        break;
    }
    
    return 0;
}