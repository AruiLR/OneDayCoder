//��֪n����Χ����һ��Բ����Χ���ӱ��Ϊk���˿�ʼ����������m���Ǹ��˳��У�������һ�����ִ�ͷ��ʼ����������m���Ǹ����ֳ��У�
//���˹����ظ���ȥ��ֱ��Բ����Χ����ȫ������

//������Լɪ�������ʵ�ʳ��������õ����ݽṹ��ѭ������
#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct ListNode
{
    int data;
    struct ListNode *next;
}node;

node *creat(int n)
{
    int i=1;
    node *head,*p,*s;
    head=(node*)malloc(sizeof(node));
    p=head;
    while(i<=n)
    {
        s=(node*)malloc(sizeof(node));
        s->data=i;
        p->next=s;
        p=s;
        i++;
    }
    head=head->next;
    p->next=head;
    return head;
}

void pop_list(node *head,int m,int k,int n)
{
    node *p=head;
    node *pop_node;
    node *pop_pre_node;
    node *tmp;
    int i=1;
    int j;
    int pop_num=0;
    while(i<k) //�ҵ����Ϊk�Ľڵ�
    {
        p=p->next;
        i++;
    }
    tmp=p;
    while(pop_num<n)
    {
        j=1;
        while(j<m-1) //�ҵ�Ҫ���е�ǰһ���ڵ�
        {
            tmp=tmp->next;
            j++;
        }
        pop_pre_node=tmp;
        pop_node=pop_pre_node->next;
        printf("%d\n",pop_node->data);
        pop_pre_node->next=pop_node->next;
        tmp=pop_node->next;
        free(pop_node);
        pop_num++;
    }

}
int main()
{
    node *head;
    int n,m,k;
    printf("������������");
    scanf("%d",&n);
    head=creat(n);
    //printf("%d\n",head->next->next->next->next->next->data);
    printf("�����뱨����ʼ��Ա��ţ�");
    scanf("%d",&k);
    printf("���������Ƶ�ʣ�");
    scanf("%d",&m);
    pop_list(head,m,k,n);
    return 0;
}
