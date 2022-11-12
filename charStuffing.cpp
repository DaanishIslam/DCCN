// charachter stuffing

#include<bits/stdc++.h>

using namespace std;

void charachterStuffing(vector<string> arr){
    vector<string> ans;

    for(int i=0;i<arr.size();i++){
        if(arr[i]=="FLAG" || arr[i]=="ESC"){
            ans.push_back("ESC");
        }

        ans.push_back(arr[i]);
    }

    cout<<"\nThe stuffed is : ";
    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<endl;

    return ;
}

int main(){
    vector<string> arr;
    cout<<"Enter the byte value : ";
    string s;
    getline(cin,s);

    string temp="";
    for(int i=0;i<s.size();i++){
        if(s[i]==' '){
            arr.push_back(temp);
            temp="";
            continue;
        }

        temp=temp+s[i];
    }

    arr.push_back(temp);


    charachterStuffing(arr);

    return 0;
}