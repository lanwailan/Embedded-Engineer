#include <stdio.h>
int MaxSubseqSum1(int a[],int N);
int main()
{
    int N =0;
    (void)scanf("%d\n",&N);
    int a[100000];
    for(int i=0;i<N;i++)
    {
        (void)scanf("%d",&a[i]);
    }
    MaxSubseqSum1(a,N);
    printf("%d\n", MaxSubseqSum1(a,N));
    return 0;
}
int MaxSubseqSum1(int a[],int N)
{
    int thissum, Maxsum = 0;
    for(int i=0;i<N;i++)
    {
        thissum +=a[i];
        if(thissum > 0)
        {
            if(Maxsum< thissum)
            {
                Maxsum = thissum;
            }
        }
        else{
            thissum = 0;
        }
    }
    return Maxsum;
}