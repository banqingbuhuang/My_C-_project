#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> b(n);
    vector<int> c(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    for(int i=0;i<n;i++){
        cin>>c[i];
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    sort(c.begin(),c.end());
    int id_a=0;
    int id_b=0;
    int id_c=0;
    unordered_map<int,vector<int>> record_a;
    unordered_map<int,vector<int>> record_b;
    for(auto x:a){
        for(auto y:b){
            if(y>x&&y<=x*2){
                record_a[x].emplace_back(y);
            }
        }
    }
    for(auto x:b){
        for(auto y:c){
            if(y>x&&y<=x*2){
                record_b[x].emplace_back(y);
            }
        }

    }
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ans+=record_a[a[i]].size()*record_b[b[j]];
        }
    }
    return 0;
}