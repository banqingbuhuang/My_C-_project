#include<iostream>
#include<bits/stdc++.h>
using namespace std;



int main(){
    int n;
    cin>>n;
    vector<int> setA(n);
    for(int i=0;i<n;i++){
      cin>>setA[i];
    }
    vector<int> vec=setA;
    sort(vec.begin(),vec.end());
    unordered_map<int,int> record;
    for(int i=0;i<n;i++){
        if(vec[i]==0){
            record[vec[i]]=0;
            continue;
        }
        if(record[vec[i-1]]!=vec[i-1]){
            record[vec[i]]=record[vec[i-1]];
        }
        else{
            for(int j=vec[i-1];j<=vec[i];j++){
                if(record.find(j)!=record.end()){
                    continue;
                }else{
                    record[vec[i]]=j;
                    break;
                }
            }
        }
    }
    for(auto x:setA){
        cout<<record[x]<<" ";
    }cout<<endl;
    return 0;
}