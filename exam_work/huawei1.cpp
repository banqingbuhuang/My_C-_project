
#include<vector>
#include<string>
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
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
int main()
{
    
    string str;
    getline(cin,str);
    // str=;
    string list;
    getline(cin,list);
    //list="what say first Second IS introduction IS end";
    string listnew="";
    for(auto x:list){
        listnew+=toupper(x);
    }
    vector<string> input_str;
    vector<string> str_list=split(listnew," ");
    unordered_map<string,int> record_list;
    for(int i=0;i<str_list.size();i++){
        record_list[str_list[i]]=i;
    }
    int i=0;
    string ans="";
    while(i<str.size()){
        if(str[i]=='"'){
            int j=i+1;
            while(j<str.size()&&str[j]!='"'){
                j++;
            }
            j++;
            ans+=str.substr(i,j-i);
            i=j;
        }else if(str[i]==' '||str[i]==','||str[i]=='.'){
            ans+=str[i];
            i++;
        }else{
            int j=i+1;
            while(j<str.size()&&str[j]!=' '&&str[j]!='"'&&str[j]!=','&&str[j]!='.'){
                j++;
            }
            string temp=str.substr(i,j-i);
            cout<<"temp"<<temp<<endl;
            string temp2="";
            for(auto x:temp){
                temp2+=toupper(x);
            }
            if(record_list.find(temp2)!=record_list.end()){
                ans+=(to_string(record_list[temp2]));
            }
            else{
                ans+=str.substr(i,j-i);
            }
            i=j;
        }
    }
    cout<<ans<<endl;
    return 0;
}
