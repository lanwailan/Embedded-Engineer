#define MaxSize 100
typedef int ElementType;
struct QNode{
    ElementType Data[MaxSize];
    int rear;
    int front;
};
typedef struct QNode *Queue;

void AddQ(Queue PtrQ,ElementType X)
{
    if((PtrQ->rear +1 )% MaxSize == PtrQ->front)
    {
        return 0;
    }
    else{
        PtrQ->rear = (PtrQ->rear +1)%MaxSize;
        PtrQ->Data[PtrQ->rear] = X;
    }
}

ElementType DeleteQ(Queue PtrQ)
{
    if(PtrQ->front == PtrQ->rear)
    {
        return 0;
    }
    else{
        PtrQ->front = (PtrQ->front +1) % MaxSize;
        ElementType X = PtrQ->Data[PtrQ->front];
        PtrQ->rear --;
        return X;
    }
}