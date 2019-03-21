#include <iostream>
#include <vector>
using namespace std;

// \brief Find value which is not repeated twice in array
// 
// Since array is sorted, just check every two values
//
// \param v vector with items
void FindNonRepeatingValue(vector<int> v)
{
    // Go through vector (advance 2 by iteration)
    for(int i=0; i<(v.size() - 1); i+=2)
    {
        // Check if item is not repeated twice
        if(v.at(i) != v.at(i+1))
        {
            cout << v.at(i) << endl;
            return;
        }
    }
    
    // Item not found and array is odd, last item is not repeating
    if( (v.size() % 2 != 0) )
    {
        cout << v.at(v.size() - 1) << endl;
        return;
    }
    // Otherwise, all items are reppeating
    return;
}

int main() {
	//code
	
	// Test cases
	unsigned int t;
	
	// Array size
	unsigned int N;
	
	// Read number of test cases
	cin >> t;
	
	// Execute test cases
	while(t--)
	{
	    // Read data
	    cin >> N;
	    vector<int> v(N, 0);
	    for(int i=0; i<N; i++)
	    {
	        cin >> v.at(i);
	    }
	    
	    // Find not repeating item
	    FindNonRepeatingValue(v);
	    
	    // Clear vector
	    v.clear();
	}
	
	return 0;
}
