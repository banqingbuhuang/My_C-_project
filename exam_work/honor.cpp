#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;
class A{
	int a;
};
vector<string> split(string s, string mode) {
	vector<string> ans;
	int i = 0;
	while ((i = s.find(mode)) && i != s.npos) {
		ans.push_back(s.substr(0, i));
		s = s.substr(i + 1);
	}
	ans.push_back(s);
	return ans;
}
int get_ser(string cmd,vector<int>& servers,vector<int>& add_servers){
	if(cmd.size()<10){
		int num=stoi(cmd.substr(6,2));
		return servers[num];
	}else{
		int num=stoi(cmd.substr(10,2));
		return add_servers[num-1];
	}
}
int hash_tockn(string token,vector<int>& servers){
	long long sum=0;
	for(int i=0;i<token.size();i++){
		sum+=token[i];
	}
	sum=sum%999;
	if(sum>950){
		return -1;
	}
	for(int i=2;i<servers.size();i++){
		if(servers[i-1]<sum&&servers[i]>=sum){
			return servers[i];
		}
	}
	return -1;
}
int hash_tockn_3(string token,vector<int>& servers){
	vector<string> com=split(token,";");
	vector<string> down=split(com[0],",");
	for(auto x:down){
		int err_s=stoi(x.substr(6,2));
		err_s=(err_s-1)*50;
		servers.erase(find(servers.begin(),servers.end(),err_s));
	}
	int ans=hash_tockn(com[1],servers);
	return ans;
}
int add_s(string com,vector<int> servers){
	if(com.size()<10){
		return -1;
	}
	int add_s=stoi(com.substr(10,2));
	return servers[add_s-1];
}
int add_s_5(string cmd,vector<int>servers,vector<int> add_servers){
	vector<string> com=split(cmd,";");
	if(com[0].size()<10){
		return -1;
	}
	int add_s=stoi(com[0].substr(10,2));
	for(int i=0;i<add_s;i++){
		servers.push_back(add_servers[i]);
	}
	sort(servers.begin(),servers.end());
	int ans=hash_tockn(com[1],servers);
	return ans;
}
int main() {
	A a;
	
	// string cmd="1:redis_01";
	string cmd="2:hongsweisesfe000";
	vector<int> servers={-1,0,50,100,150,200,250,300,350,400,450,500,550,600,650,700,750,800,850,900,950};
	vector<int> add_servers={25,525,75,575,125,625,175,675,225,725,275,775,325,825,375,875,425,925,475,975};
	if(cmd[0]=='1'){
		int num=get_ser(cmd.substr(2),servers,add_servers);
		cout<<num<<endl;
	}else if(cmd[0]=='2'){
		int num=hash_tockn(cmd.substr(2),servers);
		cout<<num<<endl;
	}else if(cmd[0]=='3'){
		int num=hash_tockn_3(cmd.substr(2),servers);
		cout<<num<<endl;
	}else if(cmd[0]=='4'){
		int num=add_s(cmd.substr(2),add_servers);
		cout<<num<<endl;
	}else if(cmd[0]=='5'){
		int num=add_s_5(cmd.substr(2),servers,add_servers);
		cout<<num<<endl;
	}
	
	
	return 0;
}