typedef int Position;
typedef int ElementType;
typedef int Bool;

#define NULL 0
#define TRUE 1
#define FALSE 0
typedef struct SNode *PtrToSNode;
struct SNode
{
    ElementType Data;
    PtrToSNode Next;
};
typedef PtrToSNode Stack;

Stack CreateStack()
{
    //头结点只有链接下一级地址，所以本身是没有数据的
    Stack S = (Stack)malloc(sizeof(struct SNode));
    S->Next = NULL;
    return S;
}

Bool IsEmpty(Stack S)
{
    return (S->Next == NULL);
}

Bool Push(Stack S, ElementType X)
{
    //申请节点空间，所以在命名的时候用SNode，指针结果。可以直接PtrToSNode
    struct SNode *P = (struct SNode *)malloc(sizeof(struct SNode));
    P->Data = X;
    P->Next = S->Next;
    S->Next = P;
    return TRUE;
}

ElementType Pop(Stack S)
{
    ElementType X;
    PtrToSNode firstCell;
    if(IsEmpty(S))
    {
        return 0;
    }
    else
    {
       firstCell = S->Next;
       S->Next = firstCell->Next;
       X = firstCell->Data;
       free(firstCell);
       return X;
    }
}