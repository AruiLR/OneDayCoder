#include<iostream>
using namespace std;
void int_convert_str(int num)
{
    char tmp[15];
    int temp;
    int index=0;
    string str;
    //�������������תΪ�ַ�����
    while(num)
    {
        tmp[index]=num%10+'0'; //������'0'������ת�����ַ�����
        index++;
        num=num/10;
    }
    //index--;
    tmp[index]=0;
    //��tmp��������
    for(int i=0,j=index-1;i<j;i++,j--)
    {
        temp=tmp[i];
        tmp[i]=tmp[j];
        tmp[j]=temp;
    }
    printf("string = %s\n",tmp);
}


int main ()
{
    int_convert_str(12345);
}
