#define FALSE 0
#define TRUE 1
#define NULL 0
typedef struct LNode *PtrToLNode;
typedef int ElementType;
struct LNode
{
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;
typedef int bool;
#define ERROR 0;

Position Find(List L,ElementType X)
{
    Position p = L;

    while(p && X != p->Data)
    {
        p = p->Next;
    }
    if(p)
    {
        return p;
    }
    else{
        return ERROR;
    }
}

bool Insert(List L,ElementType X,Position P)
{
    Position tmp,pre;
    for(pre = L;pre&&pre->Next !=P;pre=pre->Next)
    {
        if(pre == NULL)
        {
            return FALSE;
        }
        else
        {
            tmp = (Position)malloc(sizeof(struct LNode));
            tmp->Data = X;
            tmp->Next = P;
            pre->Next = tmp;
            return TRUE;
        }
    }
}

bool Delete(List L,Position P)
{
    Position pre;

    for(pre= L;pre&&pre->Next !=P;pre=pre->Next)
    {
        if(pre==NULL)
        {
            return FALSE;
        }
        else
        {

            pre->Next = P->Next;
            free(P);
            return TRUE;
        }
    }
}