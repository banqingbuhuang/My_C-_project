#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> primes;
bool isnp[INT_MAX];
unordered_map<int,int> record;
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
    cout<<primes.size()<<endl;
    // for(int i=0;i<primes.size();i++){
    //     for(int j=0;j<primes.size();j++){
    //         for(int k=0;k<primes.size();k++){
    //             int sum=primes[i]*primes[i]+primes[j]*primes[j]*primes[j]+primes[k]*primes[k]*primes[k]*primes[k];
    //             record[sum]++;
    //         }
    //     }
    // }
}
int main(){
    int t;
    cin>>t;
    init_primes(1001);
    while(t--){
        int num;
        cin>>num;
        // int ans=record[num];
        // cout<<ans<<endl;
    }
    return 0;
}