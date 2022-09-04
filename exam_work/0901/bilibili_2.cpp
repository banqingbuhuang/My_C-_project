#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> primes;
bool isnp[1000];
set<int> record;
void init_primes(int n){
    for(int i=2;i<=n;i++){
        if(!isnp[i]){
            primes.push_back(i);
        }
        for(int p:primes){
            if(p*i>n) break;
            isnp[p*i]=1;
            if(i%p==0) break;
        }
    }
    for(auto x:primes){
        cout<<x<<" ";
    }cout<<endl;
    
}
vector<vector<int>> dir{{1,0,0},{0,1,0},{0,0,1}};
void record_table(int num){
    // vector<int> idx(3,0);
    // int sum=28;
    // int step=0;
    for(int i=0;i<primes.size();i++){
        for(int j=0;j<primes.size();j++){
            for(int k=0;k<primes.size();k++){
                
                int sum=primes[i]*primes[i]+primes[j]*primes[j]*primes[j]+primes[k]*primes[k]*primes[k]*primes[k];
                if(primes[k]>=100||primes[j]>100||sum>1000000){
                    break;
                }
                record.insert(sum);
            }
        }
    }
}
int func(int num){
    int ans=0;
    // for(auto it=record.begin();it!=record.end();it++){
    //     cout<<*it<<" ";
    // }cout<<endl;
    for(auto it =record.begin();it!=record.end();it++){
        if(num>=*it){
            ans++;
        }
    }
    cout<<ans<<endl;
    return ans;
}
int main(){
    int t;
    cin>>t;
    init_primes(1000);
    
    // int ans=func(34);
    // cout<<ans<<endl;
    while(t--){
        int num;
        cin>>num;
        record_table(num);
        int ans=func(num);
        cout<<ans<<endl;
    }
    return 0;
}