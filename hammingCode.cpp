// hamming code generation

#include<bits/stdc++.h>

using namespace std;

void generateHammingCode(string s,int m,int r){
    vector<int> ans(m+r);

    for(int i=0;i<r;i++){
        int t=pow(2,i);
        ans[t-1]=-1;
    }

    int j=0;
    for(int i=0;i<(m+r);i++){
        if(ans[i]!=-1){
            ans[i]=s[j]-'0';
            j++;
        }
    }

    for(int i=0;i<ans.size();i++){
        if(ans[i]!=-1){
            continue;
        }

        int pos = log2(i+1);
        int countO=0;

        for(int j=i+2;j<=(m+r);j++){
            if((j&(1<<pos)) && (ans[j-1]==1)){
                countO++;
            }
        }

        if(countO%2==0){
            ans[i]=0;
        }
        else{
            ans[i]=1;
        }
    }

    cout<<"The hamming code for the entered bit : ";
    for(auto it:ans){
        cout<<it;
    }
    return ;
}

void findingHammingCode(string s){
    int m=s.size();
    int r=1;
    int x=2;
    while(x < (m+r+1)){
        r++;
        x=pow(2,r);
    }

    generateHammingCode(s,m,r);
}

int main(){
    cout<<"Enter the bit data : ";
    string s;
    cin>>s;

    findingHammingCode(s);

    return 0;
}