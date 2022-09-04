#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> vec;
    vector<int> div_vec;
    int max_div=0;
    int m;
    for(int i=0;i<n;i++){
        cin>>m;
        vec.emplace_back(m);
        if(i>0){
            div_vec.emplace_back(abs(vec[i]-vec[i-1]));
            max_div=max(max_div,abs(vec[i]-vec[i-1]));
        }
    }
    auto index=find(div_vec.begin(),div_vec.end(),max_div);
    
    cout<<res<<endl;
    return 0;
}