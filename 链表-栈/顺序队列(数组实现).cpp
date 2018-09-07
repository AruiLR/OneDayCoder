#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct lqueue
{
    int *data_base; //�����������
    int first;
    int rear;
}que;

que *que_init(que *PQueue,int queueCapacity)
{
    PQueue->data_base=(int *)malloc(sizeof(int)*queueCapacity); //������ָ������ڴ�
    PQueue->first=0; //��ʼ����Ϊ��ʱ��ͷָ��Ϊ0
    PQueue->rear=0;
    return PQueue;
}
que *que_push(que *PQueue,int n)
{
    //�����

    int v;
    for(int i=0;i<n;i++)
    {
        printf("������Ҫ��ӵ�Ԫ��ֵ��");
        scanf("%d",&v);
        PQueue->data_base[PQueue->rear]=v;
        PQueue->rear=PQueue->rear+1;
    }
    return PQueue;
}
que *que_pop(que *PQueue)
{
    //������

    int value;//�ݴ����Ԫ��
    if (PQueue->first==PQueue->rear)
    {
        printf("����Ϊ�գ��޳���Ԫ��\n");
    }
    else
    {
        value=PQueue->data_base[PQueue->first];
        PQueue->first=PQueue->first+1;
        printf("����Ԫ��Ϊ��%d\n",value);
    }
    return PQueue;
}
void que_traverse(que *PQueue)
{
    //���б���
    for(int i=PQueue->first;i<PQueue->rear;i++)
    {
        printf("%d\n",PQueue->data_base[i]);
    }
}

int main()
{

    int length;//���г���
    que *PQueue=(que*)malloc(sizeof(que));//�������ж���
    printf("��������г��ȣ�");
    scanf("%d",&length);
    PQueue=que_init(PQueue,length);
    PQueue=que_push(PQueue,length);
    //printf("%d",PQueue->data_base[PQueue->first]);
    PQueue=que_pop(PQueue);
    que_traverse(PQueue);
}
