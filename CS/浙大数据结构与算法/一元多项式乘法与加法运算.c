#include<stdio.h>
#include<stdlib.h>
typedef struct PolyNode *Polynomial;
struct PolyNode{
    int coef;
    int expon;
    Polynomial link;
};

Polynomial ReadPoly()
{
    int N1;
    scanf("%d",&N1);
    Polynomial p = (Polynomial)malloc(sizeof(struct PolyNode));
    Polynomial Head = p;
    for(int i=0;i<N1;i++)
    {
        int coef,expon=0;
        scanf("%d %d",&coef,&expon);
        Polynomial ptemp = (Polynomial)malloc(sizeof(struct PolyNode));
        ptemp->coef = coef;
        ptemp->expon = expon;
        p->link = ptemp;
        p = p->link;
    }
    p->link = NULL;//此时p已经链接到最后一个node 不能直接返回p
    return Head->link;
}
void PrintPoly(Polynomial p)
{
    Polynomial t = p;
    while(t)
    {
        printf("%d %d ",t->coef,t->expon);
        t = t->link;
    }
}
Polynomial Add(Polynomial L1,Polynomial L2)
{
    Polynomial p1 = L1;
    Polynomial p2 = L2;
    Polynomial L3 = (Polynomial)malloc(sizeof(struct PolyNode));
    L3->link = NULL;
    Polynomial head = L3;
    Polynomial p3;
    while(p1&&p2)
    {
        p3 = (Polynomial)malloc(sizeof( struct PolyNode));
        if(p1->expon == p2->expon)
        {
            p3->coef = p1->coef + p2->coef;
            p3->expon = p1->expon;
            p1 = p1->link;
            p2 = p2->link;
        }
        else if(p1->expon > p2->expon)
        {
            p3->coef = p1->coef;
            p3->expon = p1->expon;
            p1 = p1->link;
        }
        else
        {
            p3->coef = p2->coef;
            p3->expon = p2->expon;
            p2 = p2->link;
        }
        L3->link = p3;
        L3 = L3->link;
    }
    while(p1)
    {
        L3->link = p1;
        p1 = p1->link;
        L3 = L3->link;
    }
    while(p2)
    {
        L3->link = p2;
        p2 = p2->link;
        L3 = L3->link;
    }

    return head->link;
    
}
int main()
{
    Polynomial P1,P2,PP,PS;
    P1 = ReadPoly();
    P2 = ReadPoly();
    //PP = Mult(P1,P2);
    //PrintPoly(P1);
    PS = Add(P1,P2);
    PrintPoly(PS);
    return 0;
}
