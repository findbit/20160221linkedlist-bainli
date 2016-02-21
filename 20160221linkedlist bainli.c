#include"stdio.h"
#include"strings.h"
#include"stdlib.h"

struct node
{
    int data;
    struct node *pNext;

};

struct node * create_node(int data)
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    if(NULL == p)
    {
        printf("malloc error!");
        return(NULL);
    }
    /*清理申请到的堆内存*/
    memset(p,0,sizeof(struct node));
    p->data = data;
    p->pNext = NULL;

    return p;
    /******************************/
    /******************************/
}
void insert_tail(struct node *pH,struct node *new)
{
    int cnt = 0;


    struct node *p = pH;
    while(NULL != p->pNext )
    {
        p = p->pNext;
        cnt++;

    }
    p->pNext = new;
    pH->data = cnt + 1;


}
void insert_head(struct node *pH, struct node *new)
{
    /*第一步： 新节点的next指向原来的第一个节点*/
    new->pNext = pH->pNext;
    /*第2步： 头节点的next指向新节点的地址*/
    pH->pNext = new;
    /*第3步： 头节点中的计数要加1*/
    pH->data += 1;
}
void bianli(struct node *pH)
{
    struct node *p = pH->pNext;/*直接跨过第一个节点*/
    printf("jie dian quantity: %d\n",pH->data);
    printf("***********start**********\n");
    while(NULL != p->pNext)
    {
        printf("node data: %d.\n",p->data);
        p = p->pNext;
    }
    printf("node data: %d.\n",p->data);
    printf("***********over**********\n");
}

void bianli2(struct node *pH)
{
    struct node *p = pH;/*直接跨过第一个节点*/
    printf("jie dian quantity: %d\n",pH->data);
    printf("***********start**********\n");
    while(NULL != p->pNext)
    {

         p = p->pNext;
        printf("node data: %d.\n",p->data);
    }
    printf("***********over**********\n");
}

int main(void)
{
    struct node *pHeader = create_node(0);

    insert_head(pHeader,create_node(290));
    insert_head(pHeader,create_node(32));
    insert_head(pHeader,create_node(43));
    insert_head(pHeader,create_node(463));
    insert_tail(pHeader,create_node(567));
/*
    pHeader = create_node(1);


    pHeader->pNext = create_node(2567);


    pHeader->pNext->pNext  = create_node(3);
/******************************************/
/*

    printf("Header node data: %d\n",pHeader->data);

    printf("node2 data: %d\n",pHeader->pNext->data);

    printf("node3 data: %d\n",pHeader->pNext->pNext->data);
    printf("node3 data: %d\n",pHeader->pNext->pNext->pNext->data);

*********************************/
    bianli(pHeader);
    bianli2(pHeader);
    return(0);
}
