int binarySearchTransition(int a[], int l, int h)
{
    // Check range
    if(h >= l)
    {
    
        // Get middle index of range
        int mid = (l + h) / 2;
        
        // Check that previous item exists
        if( (mid-1) >= 0 )
        {
            // If match return index
            if( (a[mid] == 1) && (a[mid-1] == 0) )
            {
                return mid;
            }
        }
        // Otherwise recurse
        if(a[mid] == 0)
        {
            return binarySearchTransition(a, mid + 1, h);
        }
        else
        {
            return binarySearchTransition(a, 0, mid - 1);
        }
    }
    // Otherwise, 1 not found
    else
    {
        return -1;
    }
}

int transitionPoint(int arr[], int n)
{
    // Your code goes here
    // Use binary search since array is sorted
    int idx = binarySearchTransition(arr, 0, n - 1);
    
    return idx;
}
