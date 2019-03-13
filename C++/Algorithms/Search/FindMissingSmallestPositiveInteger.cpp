#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// \brief Function to find smaller missing positive integer from vector
//
//  
//
// \param Input vector
// \param Maximum possible value inside vector
void FindSmallestPositiveMissing(vector<int> v, int max)
{
    // Boolean of vector size to flag if item was found
    bool found[max] = {false};
    
    // Go through array
    for(auto d : v)
    {
        // Flag value
        found[d] = true;
    }
    // Go from 1 up to find smallest possitive missing item
    for(int i=1; i<max; i++)
    {
        // If item not found, print it
        if(!found[i])
        {
            cout << i << endl;
            return;
        }
    }
}

int main() {
	//code
	
    // Number of test cases
    unsigned int t;
    
    // Array size
    unsigned int N;
    
    // Max item value
    int max = pow(10, 6);
    
    // Read data
    cin >> t;
    
    // Vector to hold array
    vector<int> v;
    
    // Read test cases
    while(t--)
    {
        cin >> N;
        v.resize(N);
        
        // Read vector
        for(int i=0; i<N; i++)
        {
            cin >> v.at(i);
        }
        
        FindSmallestPositiveMissing(v, max);
        
        // Clear vector allocation
        v.clear();
    }
	
	return 0;
}
