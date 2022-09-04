#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;




int lastStoneWeightII(vector<int>& stones) {
    int sum=0;
    for(auto x:stones){
        sum+=x;
    }
    
    int target=sum/2;
    vector<int> dp(target+1,0);
    for(int x :stones){
        for(int i=target;i>=x;i--){
            dp[i]=max(dp[i],dp[i-x]+x);
        }
    }
    return sum-dp[target];
}
int maxArea(vector<int>& node){
    int left=0;
    int right=node.size()-1;
    int area=0;
    int max_area=0;
    while(left<right){
        int length=right-left;
        area=min(node[right],node[left])*length;
        max_area=max(area,max_area);
        if(node[left]>node[right]){
            left++;
        }else{
            right--;
        }
        cout<<"area"<<area<<endl;
    }
    return max_area;
}

int main()
{
 	vector<int> node={4,1,2,7,8};
    int ans=maxArea(node);
    cout<<ans<<endl;

	return 0;
}