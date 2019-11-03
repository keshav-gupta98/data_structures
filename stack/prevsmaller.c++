//we are given vector containing integers,we have to print a vector of integers containing the previous smaller element of each element
// if no smaller element is found then -1 is added in vector
//we will use stack in this question
// e.g if input is {1, 6, 4, 10, 2, 5} then output should be {-1, 1, 1,  4, 1, 2}

#include <iostream>
#include<stack>
#include<vector>
using namespace std;


vector<int> prevSmaller(vector<int> &arr)				//function to return resultant vactor 
{
    stack<int> s;
    int j = 0;
    vector<int>res;
    int size = arr.size();
    
    for( int i = 0; i < size; i++ )					//traversing through vector
    {
        if( i == 0 )
        {								// adding -1 for 1st element
            s.push( arr[ i ] );
            res.push_back( -1 );
            j++;
        }
        else
        {
            if( arr[ i ] <= s.top() )					// if present element is smaller than top of stack
            {
                while( !s.empty() && arr[ i ] <= s.top() )		// pop until a smaller element is found
                {
                    s.pop();
                }
                if( s.empty() )						// if no smaller element is found adding -1
                {
                    res.push_back( -1 );
                    j++;
                }
                else							// if found add that element in resultant vector
                {
                res.push_back( s.top() );
                j++;
                }
                s.push( arr[ i ] );					// push the present element in stack
            }
            else	
            {								// adding the element st top of stack in result vector
                res.push_back( s.top() );
                j++;
                s.push( arr[ i ] );
            }
        }
    }
    return res; 							//return the resultant stack
}


int main()
{
    int size;
    cout << "Enter the number of elements" << endl;
    cin >> size;
    vector<int>v;
    for( int i = 0; i < size ;i++ )
    {
    	int a;									//scanning the element of vector
    	cin >> a;
    	v.push_back(a);
    }
    
    vector<int>res = prevSmaller(v);						// calling function 
    
    for( int i = 0; i < size; i++ )						// printing the resultant vector
    cout << res[i] << " ";
    return 0;
}
