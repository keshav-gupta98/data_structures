#include <iostream>
#include<stack>
#include<vector>
using namespace std;
string func( int *arr , int n )
{
	stack< int >s1;
    	stack< int >s2;
    	int i = 0;
    	int curr = 1;
    	while( curr != n + 1 )
    	{
        	if( arr[ i ] == curr )
        	{
            		s1.push( curr );
            		curr++;
            		i++;
        	}
        	else 
        	{		
            		if( !s2.empty() && curr == s2.top() )
            		{
                		s2.pop();
                		s1.push( curr );
                		i++;
                		curr++;
            		}
            		else 
            		{
                		if( !s2.empty() && i < n )
                		{
                    			s2.push( arr[ i ] );
                    			i++;
                		}
                		else if( s2.empty() && i < n )
                		{
                    			s2.push( arr[ i ] );
                    			i++;
                		}
                		else
                		{
                    			curr++;
                		}
            		}
        	}
    	}
    	int top = n;
    	int count = 0;
   	while( !s1.empty() )
    	{
        	if( top == s1.top() )
        	{
            		count++;
        	}
        	s1.pop();
        	top--;
    	}
    	string c;
    	if( count == n )
    	c =  "yes";
    	else
   	c =  "no";
   	return c;
}

int main()
{
    int n;
    cout << "Enter the number of trucks\n";
    cin >> n;
    int j=0;
    string c[100];
   while( n!= 0 )
   { 
    	int *arr = new int[n];
    	for( int i = 0;i< n;i++)
    	cin >> arr[i];
    	c[j]= func(arr,n);
    	j++;
   	cin >> n;
    }
    for( int i = 0; i < j; i++ )
    cout << c[i] << endl;
    return 0;
}

