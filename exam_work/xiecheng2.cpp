#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> vec;
    int m;
    for(int i=0;i<n;i++){
        cin>>m;
        vec.emplace_back(m);
    }
    for(auto x :vec){
        cout<<x<<" ";
    }cout<<endl;
    int div;
    int res=INT_MIN;
    for(int i=1;i<vec.size()-1;i++){
        int gap1=max(abs(vec[i]-vec[i-1]),abs(vec[i]-vec[i+1]));
        int gap2=(abs(vec[i-1]-vec[i+1])+0.5)/2;
        res =max(min(gap1,gap2),res);
    }
    cout<<res<<endl;
    return 0;
}