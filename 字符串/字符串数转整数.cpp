#include<iostream>
#include<string>
using namespace std;
void str_convert_num(string str)
{
    int i=0;
    int sum=0;
    while(str[i])
    {
        sum=sum*10+(str[i]-'0'); //�ַ���'0'������ת����int���͵���
        i++;
    }
    cout<<sum<<endl;
}



int main()
{
    char str[15];
    cin>>str;
    str_convert_num(str);
}
