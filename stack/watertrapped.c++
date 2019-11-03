#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int trap( const vector< int > &arr ) 
{
    stack< int >s;
    int i = 0;
    int n = arr.size();
    int dist,height,top;
    int water = 0;
    while( i < n )
    {
        while( !s.empty() && arr[ i ] >= arr[ s.top() ] )
        {    
            top = s.top();
            s.pop();
            
            if( s.empty() )
            continue;
            
            dist = i - s.top() - 1;
            height = min( arr[ s.top() ], arr[ i ] ) - arr[ top ];
            water = water + dist * height;
        }
        s.push( i );
        i++;
    }
    return water;
}
   stack<int> s;
    int i = 0;
    int dist = 0;
    int height = 0;
    int water;
    while(i < arr.size())
    {
        while( !s.empty() && arr[i] >= arr[s.top()])
        {
            int top = s.top();
            s.pop();
            if(s.empty())
            continue;
            dist = i - s.top() -1;
            height = min(arr[s.top()],arr[i]) - arr[top];
            water = water + dist*height;
        }
        s.push(i);
        i++;
    }
    return water;
int main()
{
    int n;
    cout << "Enter the size" << endl;
    cin >> n;
    vector<int>v;
    for( int i = 0; i < n; i++ )
    {
    	int a;
    	cin >> a;
    	v.push_back(a);
    }
    int water=trap(v);
    cout << "The water trapped is " << water << endl;
}
