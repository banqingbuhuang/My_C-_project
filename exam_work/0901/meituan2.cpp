#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void dfs(unordered_map<int, string>& record,vector<vector<int>>& table,int idx,string& color){
    if(table[idx].size()==0){
        record[idx]=color[idx-1];
        return;
    }
    record[idx].push_back(color[idx-1]);
    for(auto x:table[idx]){
        dfs(record,table,x,color);
        record[idx]+=record[x];
    }
}
int count(unordered_map<int,string>& record,int idx){
    set<char> sec;
    for(auto x:record[idx]){
        sec.insert(x);
    }
    return sec.size();
}

int main(){
    int n=6;
    // cin>>n;
    
    vector<int> rec{1,2,2,1,4};
    // for(int i=0;i<n-1;i++){
    //     cin>>rec[i];
    // }
    string color="ABCCAD";
    // cin>>color;

    vector<vector<int>> table(n+1);

    for(int i=1;i<n;i++){
        table[rec[i-1]].emplace_back(i+1);
    }
    unordered_map<int, string> record;
    dfs(record,table,1,color);
    // for(auto it=record.begin();it!=record.end();it++){
    //     cout<<it->first<<" "<<it->second<<endl;
    // }
    for(int i=1;i<=n;i++){
        cout<<count(record,i)<<" ";
    }cout<<endl;
    return 0;
}