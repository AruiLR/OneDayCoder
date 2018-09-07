#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct lqueue
{
    int *data_base; //用来存放数组
    int first;
    int rear;
}que;

que *que_init(que *PQueue,int queueCapacity)
{
    PQueue->data_base=(int *)malloc(sizeof(int)*queueCapacity); //给数组指针分配内存
    PQueue->first=0; //初始队列为空时的头指针为0
    PQueue->rear=0;
    return PQueue;
}
que *que_push(que *PQueue,int n)
{
    //入队列

    int v;
    for(int i=0;i<n;i++)
    {
        printf("请输入要入队的元素值：");
        scanf("%d",&v);
        PQueue->data_base[PQueue->rear]=v;
        PQueue->rear=PQueue->rear+1;
    }
    return PQueue;
}
que *que_pop(que *PQueue)
{
    //出队列

    int value;//暂存出队元素
    if (PQueue->first==PQueue->rear)
    {
        printf("队列为空，无出队元素\n");
    }
    else
    {
        value=PQueue->data_base[PQueue->first];
        PQueue->first=PQueue->first+1;
        printf("出队元素为：%d\n",value);
    }
    return PQueue;
}
void que_traverse(que *PQueue)
{
    //队列遍历
    for(int i=PQueue->first;i<PQueue->rear;i++)
    {
        printf("%d\n",PQueue->data_base[i]);
    }
}

int main()
{

    int length;//队列长度
    que *PQueue=(que*)malloc(sizeof(que));//创建队列对象
    printf("请输入队列长度：");
    scanf("%d",&length);
    PQueue=que_init(PQueue,length);
    PQueue=que_push(PQueue,length);
    //printf("%d",PQueue->data_base[PQueue->first]);
    PQueue=que_pop(PQueue);
    que_traverse(PQueue);
}
