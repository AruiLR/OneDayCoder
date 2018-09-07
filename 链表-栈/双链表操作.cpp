#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

typedef struct ListNode
{
    int data; //�ڵ�ֵ
    struct ListNode *next;//���ָ��
    struct ListNode *pre;//ǰ��ָ��
}node;//����node

node *creat()
{
    //����˫����
    node *head, *p,*s;
    int x;//�ڵ�ֵ
    head=(node*)malloc(sizeof(node));
    int flag=1;//ѭ����������������ڵ�ֵx����0ʱ����ֹѭ��
    printf("������ڵ�ֵ(��0��������)��\n");
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
    //head=head->next;//ɾ��ͷ�ڵ�
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
    //˫�����ڵ�n��λ�ò���ڵ�

    if(n>length+1)
    {
        printf("����λ�ô��󣡽�Ԫ�ز����������\n");
        n=length+1;
    }
    int num=n-1;
    node *new_node,*p;
    new_node=(node*)malloc(sizeof(node));

    new_node->data=x;

    //�ҳ�Ҫ����λ�õ�ǰһ���ڵ�
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
    //����Ԫ��λ��ɾ�������е�n���ڵ�

    //�����ҵ���n���ڵ��ǰһ���ڵ㣬����n-1���ڵ�
    if (n>length+1)
    {
        n=length;
        printf("ɾ��Ԫ�ص�λ�ù���ɾ�����һ��Ԫ��\n");
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
    q=creat();//����˫����

    list_len=list_length(q);//��ȡ������
    printf("%d\n",list_len);

    //����ڵ�
    printf("���������ڵ��ֵ��\n");
    scanf("%d",&num);
    printf("���������ڵ��λ�ã�\n");
    scanf("%d",&ins_loc);
    q=ins_node(q,ins_loc,num,list_len);
    list_len+=1;

    //���ڵ�λ��ɾ���ڵ�
    printf("������Ҫɾ��Ԫ�ص�λ��\n");
    scanf("%d",&del_loc);
    q=del_node_by_data(q,del_loc,list_len);
    q=q->next;
    while(q)
    {
        printf("%d\n",q->data);
        q=q->next;
    }

    //���ڵ�ֵɾ���ڵ�
    printf("������Ҫɾ��Ԫ�ص�ֵ\n");
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
