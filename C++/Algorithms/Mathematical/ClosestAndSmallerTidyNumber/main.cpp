/* 
 * File:   main.cpp
 * Author: andresfe24
 * Description: Tidy numbers are those with non-decreasing digits
 *
 * Created on May 29, 2017, 6:55 PM
 */

/* Include Libraries */
#include <iostream>
#include <cstdlib>
#include <cstring>

/* Include Name spaces */
using namespace std;

/* Methods Declaration */
/*
 * tidyNum: Find closest and smaller tidy number
 */
char *tidyNum(char str[], int len)
{
    /* Loop from next to last to beginning to check if next digit is larger
     * than previous one */
    for (int i = len-2; i >= 0; i--)
    {
        /* If following digit is smaller */
        if (str[i] > str[i+1])
        {
            /* Decrease current digit */
            (char)str[i]--;
            
            /* Make digits from current equal to 9 */
            for (int j = i+1; j < len; j++)
            {
                str[j] = '9';
            }
        }
    }
    
    /* Return modified string */
    return str;
}

/*
 * Main function
 */
int main(int argc, char** argv)
{
    /* Input string */
    char str[] = "11333445538";
    int len = strlen(str);
    
    /* Find closest and smaller tidy number */
    char *num = tidyNum(str, len);
    cout << num;
    
    /* Return success */
    return 0;
}

