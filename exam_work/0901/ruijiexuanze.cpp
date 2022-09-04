#include<iostream>
using namespace std;
struct S{
    int a;
    int* b;
    char c;
} s;
static void func(int *arg){
    static int i=2;
    switch (*arg)
    {
    case 1:
        *arg+=++i;
        cout<<"case 1:"<<i<<" arg"<<*arg<<endl;
    case 2:
        *arg+=i<<1;
        cout<<"case 2:"<<i<<" arg"<<*arg<<endl;
    default:
        *arg-=011;
        cout<<"default"<<i<<" arg"<<*arg<<endl;
        break;
    }
}
int main(){
    s.a=300;
    s.b=(int*)500;
    cout<<s.a+s.b<<endl;
    cout<<s.a<<endl;

    int cnt=(2,1);
    func(&cnt);
    func(&cnt);
    cout<<cnt<<endl;
    int i, n = 0;
     for (int i = 2; i < 7; ++i) {
        do{
            if(i % 3) {
             continue;
            }
            --n;
            cout<<"i"<<i<<" "<<n<<endl;
        } while (!i);
        n++;
        cout<<"i"<<i<<" "<<n<<endl;
    }
    cout << n;
    return 0;
}