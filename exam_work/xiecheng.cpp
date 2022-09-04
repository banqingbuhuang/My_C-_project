#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    unsigned int q;
    int temp;
    cin>>q;
    while(q--){
        string str;
        cin>>str;
        bool flag=false;
        for(int i=str.size()-1;i>=0;i--){
            if(((str[i]-'0')&1)==0){
                swap(str[i],str[str.length()-1]);
                flag=true;
                break;
            }
        }
        if(flag){
            cout<<str<<endl;

        }else{
            cout<<-1<<endl;
        }
    }
    return 0;
}