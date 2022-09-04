#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool valid(vector<int>& s,vector<int>& t){
    if(s[0]==s[2]||s[1]==s[3]||t[0]==t[2]||t[1]==t[3]){
        return false;
    }
    return !(s[2]<=t[0]||s[3]<=t[1]||s[0]>=t[2]||s[1]>=t[3]);
}
int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
    int area1 = (ax2 - ax1) * (ay2 - ay1), area2 = (bx2 - bx1) * (by2 - by1);
    int overlapWidth = min(ax2, bx2) - max(ax1, bx1), overlapHeight = min(ay2, by2) - max(ay1, by1);
    int overlapArea = max(overlapWidth, 0) * max(overlapHeight, 0);
    return area1 + area2 - overlapArea;
}
int main(){
    int N=4;
    vector<bool> va(N,false);
    int fug=0;
    vector<vector<int>> pic{{1,1,4,3},{0,0,2,2},{2,4,4,7},{2,5,3,6}};
    sort(pic.begin(),pic.end());
    for(int i=0;i<N-1;i++){
        for(int j=i+1;j<N;j++){
            if(!va[i]&&!va[j]&&valid(pic[i],pic[j])){
                va[i]=va[j]=true;
                fug+=computeArea(pic[i][0],pic[i][1],pic[i][2],pic[i][3],pic[j][0],pic[j][1],pic[j][2],pic[j][3]);
            }
        }
    }
    cout<<fug<<endl;


}

// int N;
//     int c=0;
//     vector<vector<int>> pic(N);
//     for(int i=0;i<N;i++){
//         for(int j=0;j<4;j++){
//             cin>>c;
//             pic[i].push_back(c);
//         }
//     }