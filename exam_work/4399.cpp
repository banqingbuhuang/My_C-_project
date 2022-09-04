#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct stu{
    int a,b,c;
};
class A{
    public:
    void Func(){cout<<"AdeFunc"<<endl;Funclmplement();}
    protected:
    virtual void Funclmplement(){
        cout<<"A.func"<<endl;
    }
};
class B:public A{
    
    public:
    void Func(){
        cout<<"BdeFunc"<<endl;
        A::Funclmplement();}
    protected:
     void Funclmplement(){
        cout<<"B.func"<<endl;
    }

};
int main(){
    struct stu st[2]={{1,2,3},{4,5,6}};
    int t;
    t=st[0].a+st[1].b%st[0].c;
    cout<<t<<endl;
    B b;
    A* a=&b;
    a->Func();
    b.Func();
    
}