#include<iostream>
#include<memory.h>
using namespace std;
class A
{
    char k[4];
public:
    virtual void aa(){cout<<(int *)k<<endl;}
    virtual void ab(){cout<<"A::ab"<<endl;}
    virtual void ac(){cout<<"A::ac"<<endl;}
    virtual void ad(){cout<<"A::ad"<<endl;}
};
class B:public A
{
    char j[3];
public:
    virtual void bb(){}
};
class C:public virtual B
{
    char i[3];
public:
    virtual void cc(){}
};

int main()
{
    cout<<"sizeof(A):"<<sizeof(A)<<endl;
    cout<<"sizeof(B):"<<sizeof(B)<<endl;
    //cout<<"sizeof(C):"<<sizeof(C)<<endl;
    A a;
    a.aa();
    cout<<"虚表的地址："<<(int *)&a<<endl;
    cout<<"虚表中第一个函数的地址："<<(int*)*(int *)&a<<endl;
    cout<<"虚表中第二个函数的地址："<<(int*)*(int *)((&a)+1)<<endl;

}
