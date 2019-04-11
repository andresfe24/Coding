#include <iostream>
#include <vector>
using namespace std;

// Find kth element from sorted array made of two input arrays
void FindKthElementFromSortedArrays(vector<int> a, vector<int> b, unsigned int k)
{
    // Count elements
    // Start at 1 to account for indexing starting at 0
    unsigned int cnt = 1;
    
    // For loop indexes into arrays
    unsigned int i = 0;
    unsigned int j = 0;
    
    for(i=0, j=0; ( i<a.size() && j<b.size() ); )
    {
        if(a.at(i) <= b.at(j))
        {
            // Finish when counter equals k
            if(cnt == k)
            {
                // Print kth item
                cout << a.at(i) << endl;
                return;
            }
            
            // Advance index
            i++;
        }
        else
        {
            // Finish when counter equals k
            if(cnt == k)
            {
                // Print kth item
                cout << b.at(j) << endl;
                return;
            }
            
            // Advance index
            j++;
        }
        
        // Increase counter
        cnt++;
    }
    
    // Check if one array still needs to be checked
    // (this happens when array sizes are different)
    while(i < a.size())
    {
        if(cnt == k)
        {
            cout << a.at(i) << endl;
            return;
        }
        
        i++;
        cnt++;
    }
    
    while(j < b.size())
    {
        if(cnt == k)
        {
            cout << b.at(j) << endl;
            return;
        }
        
        j++;
        cnt++;
    }
    
    // No kth item (arrays may not have enough elements)
    cout << "-1" << endl;
}

int main() {
	//code
	
	// Test cases'=
	unsigned int t = 0;
	
	// Array sizes
	unsigned int M = 0;
	unsigned int N = 0;
	
	// Position to be found
	unsigned int k = 0;
	
	// Read test cases
	cin >> t;
	
	// Execute test cases
	while(t--)
	{
	    // Read array data
	    cin >> M >> N >> k;
	    
	    // Allocate arrays of given sizes
	    vector<int> a(M, 0);
	    vector<int> b(N,0);
	    
	    // Read arrays
	    for(int i=0; i<M; i++)
	    {
	        cin >> a.at(i);
	    }
	    
	    for(int i=0; i<N; i++)
	    {
	        cin >> b.at(i);
	    }
	    
	    // Find kth element in sorted array
	    FindKthElementFromSortedArrays(a, b, k);
	}
	
	return 0;
}
