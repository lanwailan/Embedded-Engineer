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
Polynomial Add(Polynomial P1,Polynomial P2)
{
    Polynomial p1 = P1->link;
    Polynomial p2 = P2->link;
    Polynomial P3 = (Polynomial)malloc(sizeof(struct PolyNode));
    Polynomial p3 = P3;
    
}
int main()
{
    Polynomial P1,P2,PP,PS;
    P1 = ReadPoly();
    P2 = ReadPoly();
    //PP = Mult(P1,P2);
    PrintPoly(P1);
    //PS = Add(P1,P2);
    PrintPoly(P2);
    return 0;
}