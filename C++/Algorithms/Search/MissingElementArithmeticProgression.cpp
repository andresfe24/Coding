#include <iostream>
#include <vector>
using namespace std;

void MissingElementArithmeticProgression(vector<int> v)
{
    // Store diff between items, when diff not equal previous one, pick smaller
    int prev = 0;
    int curr = 0;
    
    // Missing item
    int missing = 0;
    
    // Make sure vector has at least two items
    if(v.size() < 2)
    {
        cout << "At least two values are needed" << endl;
    }
    
    // If size is 2, missing item must be in the middle
    if(v.size() == 2)
    {
        missing = v.at(0) + ( v.at(1) - v.at(0) ) / 2;
        cout << missing << endl;
        return;
    }
    
    // Intialize
    prev = v.at(1) - v.at(0);
    
    // Go through vector
    for(int i=1; i<v.size(); i++)
    {
        curr = v.at(i) - v.at(i-1);
        // If current is larger, missing item is between i and i-1
        if(curr > prev)
        {
            missing = v.at(i) - prev;
            break;
        }
        else if(prev > curr)
        {
            missing = v.at(i-1) - curr;
        }
        // Continue searching
        prev = curr;
    }
    // Print missing item
    cout << missing << endl;
    
    return;
}

int main() {
	//code
	
	unsigned int t;
	unsigned int N;
	
	// Read input data
	cin >> t;
	while(t--)
	{
	    cin >> N;
	    vector<int> v(N, 0);
	    
	    for(int i=0; i<N; i++)
	    {
	        cin >> v.at(i);
	    }
	    MissingElementArithmeticProgression(v);
	}
	
	return 0;
}
