#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct node{
    ElemType data;
    struct node* next;
}Node;

Node* initlist()
{
    Node* head = (Node*)malloc(sizeof(Node));
    head->data = 0;
    head->next = NULL;
    return head;
}

//头插法
void inserHead(Node* L, ElemType data)
{
    Node* p = (Node*)malloc(sizeof(Node));
    p->data = data;
    p->next = L->next;
    L->next = p;
}
//遍历单链表
void listNode(Node* L)
{
    Node* p = L->next;
    while(p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
//获取尾节点
Node* get_tail(Node* L)
{
    Node* p = L;
    while (p->next != NULL)
    {
        p = p->next;
    }
    return p;
}
//尾插法
Node* inserTail(Node* tail, ElemType data)
{
    Node* p = (Node*)malloc(sizeof(Node));
    p->data = data;
    tail->next = p;
    p->next = NULL;
    return p;
}
//指定位置插入数据
int insertNode(Node* L, int pos, ElemType data)
{
    //找到插入位置的前驱节点
    Node* p = L;
    int i = 0;
    while (i < pos - 1)
    {
        p = p->next;
        i++;
        if(p == NULL)
        {
            return 0;
        }
    }
    //要插入的新节点
    Node* q = (Node*)malloc(sizeof(Node));
    q->data = data;
    q->next = p->next;
    p->next = q;
    return 1;
} 
//删除指定节点
int deleteNode(Node* L, int pos)
{
    //找到要删除位置的前驱节点
    Node* p = L;
    int i = 0;
    while (i < pos - 1)
    {
        p = p->next;
        i++;
        if(p == NULL)
        {
            return 0;
        }
    }
    if(p->next == NULL)
    {
        printf("delete pos error\n");
        return 0;
    }
    //删除节点与释放内存
    Node* q = p->next;
    p->next = q->next;
    free(q);
    return 1;
}
//获取链表长度
int GetlistLength(Node* L)
{
    Node* p = L;
    int length = 0;
    while(p->next != NULL)
    {
        p = p->next;
        length++;
    }
    return length;
}
//释放链表
void freelist(Node* L)
{
    Node* p = L->next;
    Node* q;
    while(p != NULL)
    {
        q = p->next;
        free(p);
        p = q;
    }
    L->next = NULL;
}
int main()
{
    Node* list = initlist();
    inserHead(list, 10);
    inserHead(list, 20);
    inserHead(list, 30);
    Node* tail = get_tail(list);
    tail = inserTail(tail, 10);
    tail = inserTail(tail, 20);
    tail = inserTail(tail, 30);
    insertNode(list, 4, 99);
    int length = GetlistLength(list);
    printf("The length of list: %d \n", length);
    listNode(list);
    deleteNode(list, 3);
    deleteNode(list, 4);
    length = GetlistLength(list);
    printf("The length of list: %d \n", length);
    listNode(list);
    freelist(list);
    length = GetlistLength(list);
    printf("The length of list: %d \n", length);
    return 0;
}