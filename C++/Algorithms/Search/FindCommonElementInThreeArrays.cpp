#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Find elements common to the three arrays
// First Approach: Go linearly through N1 (O(n)),
//    for each element do binary search (O(log(n))) in the other two arrays
//    (With this, I was getting runtime too long)
// Second Approach: Use unordered map for each vector
void FindCommonElements(vector<int> v1, vector<int> v2, vector<int> v3)
{
    // Found flag
    bool found = false;
    
    // Map to store vector items in 1
    unordered_map<int, bool> umap1;
    
    // Map to store items in vector 1 and 2
    unordered_map<int, bool> umap2;
    
    // Map to store items in vector 1, 2 and 3    
    unordered_map<int, bool> umap3;

    // Go trhough vector 1 to store all of its items
    for(int i=0; i<v1.size(); i++)
    {
        umap1.insert(pair<int,bool>(v1.at(i), true));
    }
    
    // Go through array 2
    for(int i=0; i<v2.size(); i++)
    {
        // Check that item is present in vector 1
        if( umap1.find(v2.at(i)) != umap1.end() )
        {
            umap2.insert(pair<int,bool>(v2.at(i), true));
        }
    }
    
    // Go through array 3
    for(int i=0; i<v3.size(); i++)
    {
        // Check that item is present in vectors 1 and 2
        if( umap2.find(v3.at(i)) != umap2.end() )
        {
            // Set flag
            found = true;
            
            // If not in, store it
            if( umap3.find(v3.at(i)) == umap3.end() )
            {
                // Insert it and print it
                umap3.insert(pair<int,bool>(v3.at(i), true));
                cout << v3.at(i) << " ";
            }
        }
    }
    
    // Print -1 if not found
    if(!found)
    {
        cout << "-1";
    }
    
    cout << endl;
}

int main() {
	//code
	
	// Number of test cases
	unsigned int t = 0;
	
	// Array sizes
	unsigned int N1 = 0;
	unsigned int N2 = 0;
	unsigned int N3 = 0;
	
	// Read input data
	cin >> t;
	while(t--)
	{
	    // Read sizes
	    cin >> N1 >> N2 >> N3;
	    
	    // Create vectors
	    vector<int> v1(N1, 0);
	    vector<int> v2(N2, 0);
	    vector<int> v3(N3, 0);
	    
	    // Read arrays
	    for(int i=0; i<N1; i++)
	    {
	        cin >> v1.at(i);
	    }
	    for(int i=0; i<N2; i++)
	    {
	        cin >> v2.at(i);
	    }
	    for(int i=0; i<N3; i++)
	    {
	        cin >> v3.at(i);
	    }
	    // Find common elements
	    FindCommonElements(v1, v2, v3);
	    
	    // Clear vectors
	    v1.clear();
	    v2.clear();
	    v3.clear();
	}
	
	return 0;
}
