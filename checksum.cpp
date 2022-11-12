// checksum

#include<bits/stdc++.h>

using namespace std;

string findSum(string a,string b){

    string ans="";
    int carry=0;
    for(int i=a.size()-1;i>=0;i--){
        if(a[i]=='1' && b[i]=='1'){
            if(carry==1){
                ans+="1";
            }
            else{
                ans+="0";
            }

            carry=1;
        }
        else if((a[i]=='1' && b[i]=='0') || (a[i]=='0' && b[i]=='1')){
            if(carry==1){
                ans+="0";
            }
            else{
                ans+="1";
            }
        }
        else{
            if(carry==1){
                ans+="1";
            }
            else{
                ans+="0";
            }
            carry=0;
        }
    }

    while(carry==1){
        for(int i=0;i<ans.size();i++){
            if(ans[i]=='1'){
                ans[i]='0';
            }
            else{
                ans[i]='1';
                carry=0;
                break;
            }
        }
    }

    reverse(ans.begin(),ans.end());
    return ans;
}

string compliment(string s){
    for(int i=0;i<s.size();i++){
        if(s[i]=='0'){
            s[i]='1';
        }
        else{
            s[i]='0';
        }
    }

    return s;
}

void checkSumArr(vector<string> arr){

    vector<string> ans = arr;
    while(arr.size()>1){
        int n=arr.size();
        string a=arr[n-1];
        string b=arr[n-2];
        arr.pop_back();
        arr.pop_back();

        string temp = findSum(a,b);
        arr.push_back(temp);
    }

    ans.push_back(compliment(*arr.begin()));

    cout<<"\nThe checksum generated code is : ";
    for(auto it:ans){
        cout<<it;
    }
    cout<<endl;
}

int main(){
    vector<string> arr;
    cout<<"Enter the data bit : ";
    string s;
    cin>>s;

    // divinding the string in length of 4
    string temp="";
    for(int i=0;i<s.size();i++){
        if(temp.size()==4){
            arr.push_back(temp);
            temp="";
        }

        temp=temp+s[i];
    }

    if(temp.size()>0){
        if(temp.size()<4){
            int x=4-temp.size();
            while(x--){
                temp="0"+temp;
            }
        }

        arr.push_back(temp);
    }
    

    checkSumArr(arr);

    return 0;
}