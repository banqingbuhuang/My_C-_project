#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void tail(vector<vector<char>>& pic,int n,int m){
    int num=1;
    while(n*num<m){
        num+=2;
    }
    vector<vector<char>> ans(num*n,vector<char>(num*n));
    for(int i=0;i<num*n;i++){
        for(int j=0;j<num*n;j++){
            ans[i][j]=pic[i%n][j%n];
        }
    }
    vector<vector<char>> re(m,vector<char>(m));
    int rang=m/2;
    int mid=num*n/2;
    int div=mid-rang;
    for(int i=mid;i>=mid-rang;i--){
        for(int j=mid;j>=mid-rang;j--){
            re[i-div][j-div]=ans[i][j];
        }
        for(int j=mid;j<=mid+rang;j++){
            re[i-div][j-div]=ans[i][j];
        }
    }
    for(int i=mid;i<=mid+rang;i++){
        for(int j=mid;j>=mid-rang;j--){
            re[i-div][j-div]=ans[i][j];
        }
        for(int j=mid;j<=mid+rang;j++){
            re[i-div][j-div]=ans[i][j];
        }
    }
    pic=re;
}
int main(){

    int N,M;
    cin>>N>>M;
    char c;
    vector<vector<char>> picture(N);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>c;
            picture[i].push_back(c);
        }
    }
    tail(picture,N,M);
    return 0;
}