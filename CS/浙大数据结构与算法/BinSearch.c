Position BinarySearch( List L, ElementType X )
{
    int low =0;
    int high = L->Last;
    while(low <=high)
    {
        int mid = (low+high)/2;
        if(X == L->Data[mid])
        {
            return mid;
        }else if(X > L->Data[mid])
        {
            low = mid+1;
        }else{
            high = mid -1;
        }
    }
    return NotFound;
}