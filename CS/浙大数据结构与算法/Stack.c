typedef int Position;
typedef int ElementType;
typedef int Bool;

#define TRUE 1
#define FALSE 0
#define ERROR 0;
struct SNode
{
    ElementType *Data;
    Position Top;
    int MaxSize;
    /* data */
};
typedef struct SNode *Stack;

Stack CreateStack(int Maxsize)
{
    Stack S = (Stack)malloc(sizeof(struct SNode));
    S->MaxSize = Maxsize;
    S->Data = (ElementType *)malloc(sizeof(ElementType));
    S->Top = -1;
}

Bool IsFull(Stack S)
{
    return (S->Top == S->MaxSize -1);
}

Bool Push(Stack S,ElementType X)
{
    if(IsFull(S))
    {
        return FALSE;
    }
    else
    {
        S->Data[(++S->Top)] = X;
        return TRUE;
    }
    
}
Bool IsEmpty(Stack S)
{
    return (S->Top == (-1));
}
ElementType Pop(Stack S)
{
    ElementType X;
    if(!IsEmpty(S))
    {
        X = S->Data[(S->Top)--];
    }
    else
    {
        X = ERROR;
    }
}

