#include<iostream>
using namespace std;
void foo(char str[128]){
    char chArray[]="http://www/hikvision.com";
    char *p=chArray;
    cout<<sizeof(chArray)<<" "<<sizeof(str)<<" "<<sizeof(p)<<endl;
}
int main(){
    char str[128]={'0'};
    foo(str);
    return 0;
}