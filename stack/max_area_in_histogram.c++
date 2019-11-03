//Find the largest rectangular area possible in a given histogram where the largest rectangle can be made of a number of contiguous bars.

#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int largestRectangleArea(vector<int> &v) {					//function to return max area
    int n = v.size();
    stack<int> s;
    int i = 0;
    int max = 0;
    int area = 0;
    while( i < n )								//traversing through vector
    {
        if( s.empty() || v[ i ] >= v[ s.top() ] )				// adding the index of bar if stack is empty or present bar 
        {									// is greater than the height of bar present at index at top 
            s.push( i );							// of stack
            i++;
        }
        else
        {
            while( !s.empty() && v[ s.top() ] > v[ i ] )			// if height at present index is smaller than height
            {									// at index present at top of stack 
                int x = s.top();						// performing pop until greater element is found
                s.pop();
                if( s.empty() == true )
                {
                    area = v[ x ] * i;
                }
                else
                {
                    area = v[ x ] * ( i - s.top() - 1 );
                }
            }
        }
        if( area > max )
        max = area;
    }
    i=0;
    while( !s.empty() )								// if stack is stil is not empty 
    {
        int x = s.top();
        s.pop();
        if( s.empty() == true )
        {
            area = v[ x ] * i;
        }
        else
        {
            area = v[ x ] * ( i - s.top() - 1 );			// area bounded will be height at index*distance between i and top
        }
        if( area > max )
        max = area;
    }
    return max;
}


int main()
{
    vector<int> v;
    for( int i = 0 ; i < 8; i++ )
    {
        int x;
        cin >> x;									//scanning heights of bar
        v.push_back( x );
    }
    int max=largestRectangleArea(v);
    cout << max;
    return 0;
}
