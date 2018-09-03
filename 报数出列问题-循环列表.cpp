//已知n个人围坐在一张圆桌周围，从编号为k的人开始报数，数到m的那个人出列；他的下一个人又从头开始报数，数到m的那个人又出列；
//依此规律重复下去，直到圆桌周围的人全部出列

//本题是约瑟夫环问题的实际场景，采用的数据结构是循环链表
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
    while(i<k) //找到编号为k的节点
    {
        p=p->next;
        i++;
    }
    tmp=p;
    while(pop_num<n)
    {
        j=1;
        while(j<m-1) //找到要出列的前一个节点
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
    printf("请输入人数：");
    scanf("%d",&n);
    head=creat(n);
    //printf("%d\n",head->next->next->next->next->next->data);
    printf("请输入报数开始人员编号：");
    scanf("%d",&k);
    printf("请输入出列频率：");
    scanf("%d",&m);
    pop_list(head,m,k,n);
    return 0;
}
