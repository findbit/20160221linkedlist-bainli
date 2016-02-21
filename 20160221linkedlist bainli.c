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
    /*�������뵽�Ķ��ڴ�*/
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
    /*��һ���� �½ڵ��nextָ��ԭ���ĵ�һ���ڵ�*/
    new->pNext = pH->pNext;
    /*��2���� ͷ�ڵ��nextָ���½ڵ�ĵ�ַ*/
    pH->pNext = new;
    /*��3���� ͷ�ڵ��еļ���Ҫ��1*/
    pH->data += 1;
}
void bianli(struct node *pH)
{
    struct node *p = pH->pNext;/*ֱ�ӿ����һ���ڵ�*/
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
    struct node *p = pH;/*ֱ�ӿ����һ���ڵ�*/
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
