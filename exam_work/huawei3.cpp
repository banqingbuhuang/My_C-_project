#include<vector>
#include<string>
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
const int inf=0x3f3f3f3f;
int dp[100001];
int distence[100001];
int wait_time[100001];
int main(){
    int lutu;
    cin>>lutu;
    int N_co;
    cin>>N_co;
    for(int i=1;i<=N_co;i++){
        cin>>distence[i]>>wait_time[i];
        wait_time[i]++;
    }
    distence[N_co+1]=lutu;
    memset(dp,inf,sizeof(dp));
    dp[0]=0;
    for(int i=1;i<=N_co+1;i++){
        for(int j=i-1;j>=0;j--){
            if(distence[i]-distence[j]>1000){
                break;
            }
            dp[i]=min(dp[i],dp[j]);
        }
        if(dp[i]==inf){
            cout<<-1<<endl;
            return 0;
        }
        dp[i]+=wait_time[i];
    }
    int res=lutu/100;
    
    cout<<dp[N_co+1]+res<<endl;
    return 0;
}