#include<iostream>
#include<string>
using namespace std;
struct A{
    int x;
    char y;
    char z;
    char c;
};
int main(){
    int a =1;
    int b=2;
    A* neA=new(&a) A;
    cout<<neA->y<<endl;

    string str;
    str.append("1");
    cout<<str<<endl;
    return 0;
}