/*
The stock span problem is a financial problem where we have a series of n daily price quotes for a stock and we need to calculate 
span of stock’s price for all n days.
The span Si of the stock’s price on a given day i is defined as the maximum number of consecutive days just before the given day, 
for which the price of the stock on the current day is less than or equal to its price on the given day.
For example, if an array of 7 days prices is given as {100, 80, 60, 70, 60, 75, 85}, then the span values for corresponding 7 days
are {1, 1, 1, 2, 1, 4, 6}

we will use stack here
*/

// price[i] is greater than elements after 
// i.e., price[0], price[1], ..price[i-1].  Else
// greater than all elements on left of it,
// If stack becomes empty, then price[i] is 
#include<iostream>
#include<stack>
using namespace std;

int * func( int *arr, int n)                                                       // function will retrurn resultant array
{
    stack<int>s;
    s.push(0);
    
    int *res=new int[n];
    res[0]=1;
    for( int i = 1; i < n; i++ )
    {
        while( !s.empty() && arr[ s.top() ] <= arr[ i ] )		// pop till the a element greater than the present element is found 
        {								// in stack
            s.pop();							
        }
        if( s.empty() == true )						// If stack becomes empty, then price[i] is
        {								// greater than all elements on left of it,
            res[ i ] = i + 1;				// i.e., price[0], price[1], ..price[i-1].Else				 
        }						// price[i] is greater than elements after
        else						// top of stack
        {
            res[ i ] = i - s.top();
        }
        s.push( i );					// Push this element to stack
    }
    return res;
}


int main()
{
    cout << "Enter the size of histogram" << endl;
    int n;
    cin >> n;
    int *arr = new int[n];
    for( int i = 0; i < n; i++ )
    {
        cin >> arr[i];
    }									// entering the heights of histogram
    int *res = func( arr, n );
    cout << "{ ";
    for( int i = 0; i < n; i++)
    {
        cout << res[i] << " ";
    }
    cout << "}" << endl;
}
