/* 
 * Description: Find sum of all sub-arrays of given
 *              array of integers
 */

/* Include libraries */
#include <cstdlib>
#include <iostream>

/**
 * Compute sum of sub arrays
 * @param arr Input array
 * @param n Array size
 * @return Sum of sub arrays
 */
long int SumOfSubarrays(int arr[], int n)
{
    /* Initialize result */
    long int result = 0;
    
    /* Pick starting point */
    for (int i = 0; i < n; i++)
    {
        /* Pick ending point */
        for (int j = i; j< n; j++)
        {
            /* Add sub-array between starting and ending points */
            for (int k = i; k <= j; k++)
            {
                std::cout << "Current Array Index: " << k << std::endl;
                result += arr[k];
            }
        }
    }
    
    /* Return sum of sub-arrays */
    return result;
}

/*
 * Main method
 */
int main(int argc, char** argv)
{
    /* Array for testing */
    int arr[] = {1, 2, 3};
    
    /* Get the size */
    int n = sizeof(arr) / sizeof(arr[0]);
    
    std::cout << "Sum of Subarrays: "
            << SumOfSubarrays(arr, n) << std::endl;
    
    /* Return success */
    return 0;
}

