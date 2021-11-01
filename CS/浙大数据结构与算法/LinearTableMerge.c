本题要求实现一个函数，将两个链表表示的递增整数序列合并为一个非递减的整数序列。

函数接口定义：
List Merge( List L1, List L2 );
其中List结构定义如下：

typedef struct Node *PtrToNode;
struct Node {
    ElementType Data; /* 存储结点数据 */
    PtrToNode   Next; /* 指向下一个结点的指针 */
};
typedef PtrToNode List; /* 定义单链表类型 */
L1和L2是给定的带头结点的单链表，其结点存储的数据是递增有序的；函数Merge要将L1和L2合并为一个非递减的整数序列。应直接使用原序列中的结点，返回归并后的带头结点的链表头指针。

裁判测试程序样例：
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表；空链表将输出NULL */

List Merge( List L1, List L2 );

int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}

/* 你的代码将被嵌在这里 */
输入样例：
3
1 3 5
5
2 4 6 8 10
结尾无空行
输出样例：
1 2 3 4 5 6 8 10 
NULL
NULL
结尾无空行

List Merge( List L1, List L2 )
{
    List p1 = L1->Next;
    List p2 = L2->Next;
    List L3 = (List)malloc(sizeof(struct Node));
    L3->Next = NULL;
    List p3 = L3;
    
    while(p1&&p2)
    {
        if(p1->Data > p2->Data)
        {
            p3->Next = p2;
            p2 = p2->Next;
        }
        else{
            p3->Next = p1;
            p1 = p1->Next;
        }
        p3 = p3->Next;
    }
    while(p1)
    {
        p3->Next = p1;
        p1 = p1->Next;
        p3 = p3->Next;
    }
    while(p2)
    {
        p3->Next = p2;
        p2 = p2->Next;
        p3 = p3->Next;
    }
    L1->Next = NULL;
    L2->Next = NULL;
    return L3;
    
 
}