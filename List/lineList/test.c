#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define datasize 100
typedef int Elemtype;

// typedef struct  
// {
//     Elemtype data[datasize];
//     int length;
// }SeqList;

typedef struct  
{
    Elemtype *data;
    int length;
}SeqList;

SeqList* initSeqList()
{
    SeqList* L = (SeqList*)malloc(sizeof(SeqList));
    L->data = (Elemtype*)malloc(sizeof(Elemtype)*datasize);
    L->length = 0;
    return L;
}
//尾部添加元素
int addListData(SeqList *L, Elemtype data)
{
    if(L->length >= datasize)
    {
        return 0;
    }
    L->data[L->length] = data;
    L->length++;
    return 1;
}
//遍历元素
void ListElem(SeqList *L)
{
    for(int i = 0; i < L->length; i++)
    {
        printf("%d ", L->data[i]);
    }
    printf("\n");
}
//中间插入元素
int inserElem(SeqList *L, int pos, Elemtype data)
{
    if(L->length >= datasize)
    {
        printf("List full\n");
        return 0;
    }
    if((pos < 1) || (pos > L->length))
    {
        printf("inser pos error\n");
        return 0;
    } 
    if(pos <= L->length)
    {    
        for(int i = (L->length - 1); i >= (pos - 1); i--)
        {
            L->data[i+1] = L->data[i];
        }
        L->data[pos-1] = data;
        L->length++;
        return 1;
    }
}
int deleteElem(SeqList *L, int pos)
{
    if((pos < 1) || (pos > L->length))
    {
        printf("delete pos error\n");
        return 0;
    } 
    if(pos <= L->length)
    {    
        for(int i = (pos - 1); i < (L->length - 1); i++)
        {
            L->data[i] = L->data[i+1];
        }
        L->length--;
        return 1;
    }
}
//查找数据位置
int findElem(SeqList *L, Elemtype data)
{
    if(L->length == 0)
    {
        printf("List NULL\n");
        return 0;
    }
    for(int i = 0; i < L->length; i++)
    {
        if(L->data[i] == data)
        {
            printf("Element %d found at position :%d\n", data, (i+1));
            return i + 1;
        }
    }
    printf("Element %d not found\n", data);
    return 0;  
}
int main()
{
    SeqList* list = initSeqList();
    printf("Init succes,Length: %d\n", list->length);
    printf("the Size of List: %zu\n", sizeof(list->data));
    addListData(list, 13);   
    addListData(list, 25);    
    addListData(list, 37);    
    addListData(list, 23);    
    addListData(list, 19);
    ListElem(list);
    inserElem(list, 3, 22);
    ListElem(list);
    int pos1 = findElem(list, 37);
    deleteElem(list, 4);
    int pos2 = findElem(list, 99);
    ListElem(list);  

    return 0;
}