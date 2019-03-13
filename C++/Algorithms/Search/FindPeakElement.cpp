// \brief The function returns the index of any peak element
//
// Peak is an element which is larger than its neighbors
//
// \param input array
// \param array size
//
// \return peak element index
int peak(int a[], int n)
{
    // Find index of a peak element
    // Check first and last item
    if(n >= 2)
    {
        // Check if first element is a peak element
        if(a[0] > a[1])
        {
            return 0;
        }
        // Check if last is peak
        if(a[n-1] > a[n-2])
        {
            return (n-1);
        }
    }
    // Check remaining items
    for(int i=1; i<(n-1); i++)
    {
        if( (a[i] > a[i-1]) && (a[i] > a[i+1]) )
        {
            return i;
        }
    }
}
