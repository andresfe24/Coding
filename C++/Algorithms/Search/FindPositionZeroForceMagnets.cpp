#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Get force at position x
double Force(vector<int> v, double pos)
{
    // Total force
    double f = 0;
    
    // Get force at pos from all magnets
    for(int i=0; i<v.size(); i++)
    {
        // This will add values from left, and susbatrct items from right
        f += ( 1 / (pos - v.at(i)) );
    }
    
    // return totoal force at pos
    return f;
}

// Find the zero force location within given slot (in between two items)
double CheckSlot(vector<int> v, double l, double r)
{
    // Middle item
    double mid;
    
    // Check limits (assume order as we are talking about positions)
    while(r > l)
    {
        // Find middle position
        mid = r + (l - r)*0.50;
        
        // Find force at middle position
        double val = Force(v, mid);
        
        // If value is close enough to zero, return it as solution
        if(abs(val) < 0.0000000000001)
        {
            return mid;
        }
        
        // Iterate based on whether absolute froce is to the right or left
        // in current position
        if(val > 0)
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }
    return l;
}

// Find zero force positions
// Algorithm: Iteratively do search to find 0 force positions
void FindZeroForceMagnetsPositions(vector<int> v)
{
    for(int i=1; i<v.size(); i++)
    {
	    printf("%0.2f ", CheckSlot(v, v.at(i-1), v.at(i)) );
    }
    cout << endl;
}

int main() {
	//code
	
	// Test cases
	unsigned int t = 0;
	
	// Array size
	unsigned int N = 0; 
	
	// Read number of test cases
	cin >> t;
	
	// Go through all test cases
	while(t--)
	{
	    // Read size and vector
	    cin >> N;
	    vector<int> v(N, 0);
	    for(int i=0; i<N; i++)
	    {
	        cin >> v.at(i);
	    }
	    // Find zero force positions
	    FindZeroForceMagnetsPositions(v);
	    
	    // Clear vector
	    v.clear();
	}
	
	return 0;
}
