#include<vector>
#include<string>
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
vector<vector<int>> dir{{1,0},{-1,0},{0,1},{0,-1}};
int res=INT_MAX;

void dfs(vector<vector<int>>& migong,int time,int n,int m,int x,int y){
    if(x<0||x>=n||y<0||y>=m||migong[x][y]==1||migong[x][y]==5){
        return;
    }
    time++;
    int tmp=migong[x][y];
    if(tmp==3){
        res=min(res,time);
        return;
    }
    migong[x][y]=5;
    vector<int> tmp_vec(4);
    if(tmp==4){
        time+=2;
    }else if(tmp==6){
        for(int i=0;i<4;i++){
            int new_x=x+dir[i][0];
            int new_y=y+dir[i][1];
            if(new_x>=0&&new_x<n&&new_y>=0&&new_y<m){
                tmp_vec[i]=migong[new_x][new_y];
                if(tmp_vec[i]==1){
                    migong[new_x][new_y]=0;
                }
            }
        }
    }
    for(int i=0;i<4;i++){
        int next_x=x+dir[i][0];
        int next_y=y+dir[i][1];
        dfs(migong,time,n,m,next_x,next_y);
    }
    migong[x][y]=tmp;
    if(tmp==6){
        for(int i=0;i<4;i++){
            int new_x=x+dir[i][0];
            int new_y=y+dir[i][1];
            if(new_x>=0&&new_x<n&&new_y>=0&&new_y<m){
                migong[new_x][new_y]=tmp_vec[i];
            }
        }
    }
    //cout<<time<<endl;;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> migong(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>migong[i][j];
        }
    }
    int time=-1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(migong[i][j]==2){
                dfs(migong,time,n,m,i,j);
            }
        }
    }
    cout<<res<<endl;
}