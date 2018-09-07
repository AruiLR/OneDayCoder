#include<iostream>
#include<string>
using namespace std;
char *strcpy(char *strDest,char *strSrc)
{
    char *address=strDest;
    while(*strSrc!='\0')
    {
        *strDest++=*strSrc++;
    }
    return address;
}

int main()
{
    char *strdest;
    char *strsrc="hello world";
    strdest=(char *)malloc(20);
    char *Dest=strdest;

//    Dest=strcpy(strdest,strsrc);
    while(*strsrc!='\0')
    {
        *strdest=*strsrc;
        strdest++;
        strsrc++;
    }
    while(*Dest!='\0')
    {
        cout<<*Dest;
        Dest++;
    }
    return 0;

}
