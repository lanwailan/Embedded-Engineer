#define MAXSIZE 100
#define ERROR -1
#define FALSE 0
#define TRUE 1
typedef int bool;
typedef int Position;
typedef int ElementType;
typedef struct LNode* List;
struct LNode
{
    ElementType Data[MAXSIZE];
    Position Last;
};

List MakeEmpty()
{
    List L;
    L = (List)malloc(sizeof(struct LNode));
    L->Last = -1;
    return L;
}

Position Find(List L,ElementType X)
{
    for(int i=0;i< L->Last;i++)
    {
        if(X == L->Data[i])
        {
            return i;
        }
    }
    return ERROR;
  /*  
    Position i =0;
    while(i < L->Last && X != L->Data[i])
    {
        i ++;
    }
    if(i>L->Last)
    {
        return ERROR;
    }
    else{
        return i;
    }
    */
}

bool Insert(List L,ElementType X,Position P)
{
    if(L->Last == MAXSIZE -1)
    {
        return FALSE;
    }
    if(P < 0 || P > MAXSIZE -1)
    {
        return FALSE;
    }
    for(int i = L->Last;i > P;i--)
    {
        L->Data[i+1] = L->Data[i];
    }
    L->Data[P] = X;
    L->Last ++;
    return TRUE;
}

bool Delete(List L,Position P)
{
    if(L->Last == 0)
    {
        return FALSE;
    }
    if(P <0 || P > L->Last)
    {
        return FALSE;
    }

    for(int i=P;i< L->Last;i++)
    {
        L->Data[i] = L->Data[i+1];
    }

    L->Last --;
    return TRUE;
}
