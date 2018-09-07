#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

typedef struct ListNode
{
    int data; //节点值
    struct ListNode *next;//后继指针
    struct ListNode *pre;//前驱指针
}node;//别名node

node *creat()
{
    //创建双链表
    node *head, *p,*s;
    int x;//节点值
    head=(node*)malloc(sizeof(node));
    int flag=1;//循环控制条件，输入节点值x等于0时，终止循环
    printf("请输入节点值(以0结束输入)：\n");
    p=head;
    while(flag)
    {

        scanf("%d",&x);
        if(x!=0)
        {
            s=(node*)malloc(sizeof(node));
            s->data=x;
            p->next=s;
            s->pre=p;
            p=s;
        }
        else
        {

            flag=0;
        }
    }
    //head=head->next;//删除头节点
    head->pre=NULL;
    p->next=NULL;
    return head;
}
int list_length(node *head)
{
    int len=0;
    node *p;
    p=head;
    p=p->next;
    while(p)
    {
        len++;
        p=p->next;
    }
    return len;
}
node *ins_node(node *head,int n,int x,int length)
{
    //双链表在第n个位置插入节点

    if(n>length+1)
    {
        printf("插入位置错误！将元素插入链表最后\n");
        n=length+1;
    }
    int num=n-1;
    node *new_node,*p;
    new_node=(node*)malloc(sizeof(node));

    new_node->data=x;

    //找出要插入位置的前一个节点
    p=head;
    while(num)
    {
        p=p->next;
        num--;
    }

    if (n==length+1)
    {
        new_node->next=p->next;
        new_node->pre=p;
        p->next=new_node;
    }
    else
    {
        new_node->next=p->next;
        new_node->pre=p;
        p->next->pre=new_node;
        p->next=new_node;
    }
    return head;
}

node *del_node_by_loc(node *head,int n,int length)
{
    //根据元素位置删除链表中第n个节点

    //首先找到第n个节点的前一个节点，即第n-1个节点
    if (n>length+1)
    {
        n=length;
        printf("删除元素的位置过大，删除最后一个元素\n");
    }
    int tmp=n-1;
    node *p,*q;
    p=head;
    while(tmp)
    {
        p=p->next;
        tmp--;
    }
    if(n==length)
    {
        p->next=NULL;
        free(q);
    }
    else
    {
        q=p->next;
        p->next=q->next;
        q->next->pre=p;
        free(q);
    }
    return head;
}
node *del_node_by_data(node *head,int data,int length)
{
    node *p,*s;
    p=head->next;
    while(p->data!=data)
    {
        p=p->next;
    }
    printf("%d\n",p->data);
    s=p->pre;
    if(p->next==NULL)
    {
        s->next=NULL;
        free(p);
    }
    else
    {
        s->next=p->next;
        p->next->pre=s;
        free(p);
    }
    return head;
}
int main()
{
    node *q;
    int list_len;
    int num,ins_loc,del_loc,data;
    q=creat();//创建双链表

    list_len=list_length(q);//获取链表长度
    printf("%d\n",list_len);

    //插入节点
    printf("请输入插入节点的值：\n");
    scanf("%d",&num);
    printf("请输入插入节点的位置：\n");
    scanf("%d",&ins_loc);
    q=ins_node(q,ins_loc,num,list_len);
    list_len+=1;

    //按节点位置删除节点
    printf("请输入要删除元素的位置\n");
    scanf("%d",&del_loc);
    q=del_node_by_data(q,del_loc,list_len);
    q=q->next;
    while(q)
    {
        printf("%d\n",q->data);
        q=q->next;
    }

    //按节点值删除节点
    printf("请输入要删除元素的值\n");
    scanf("%d",&data);
    q=del_node_by_data(q,data,list_len);
    q=q->next;
    while(q)
    {
        printf("%d\n",q->data);
        q=q->next;
    }


    return 0;
}
