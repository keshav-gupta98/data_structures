//we have to find the molecular mass of given compund
// the chemical formula should contain only C,H,O
// we will use stack in this question

#include <iostream>
#include<stack>
#include<string>
#include <sstream> 
using namespace std;

int massof( char c )
{										//function to return mass of element C,H,O
    if( c == 'C' )
    return 12;
    if( c == 'O' )
    return 16;
    return 1;
}

int calmass( string str )
{
    stack< int >s;
    int i = 0;
    
    while( str[ i ] != '\0' )							//traversing through string
    {
        if( str[ i ] == 'C' || str[ i ] == 'H' || str[ i ] == 'O' )		//add mass of element C,H,O in stack
        {
            s.push( massof( str[ i ] ) );
            i++;
        }
        else
        {
            if( str[ i ] == '(' )						//add -1 in stack if '(' is found
            {
                s.push( -1 );
                i++;
            }
            else
            {
                if( str[ i ] == ')' )					// if ')' is found pop until -1 is found add the sum of 
                {							// all those elements
                    int value = 0;
                    while( s.top() != -1 )
                    {
                        value = value + s.top();
                        s.pop();
                    }
                    s.pop();
                    s.push( value );
                    i++;
                }
                else
                {
                    string b = "";						//if integer is found
                    while( str[ i ] >= '0' && str[ i ] <= '9' )			// add intger*s.top()
                    {
                        b = b + str[ i ];
                        i++;
                    }
                    
                    stringstream a( b );					//to convert string to intger
                    int val = 0;
                    a >> val;
                    int x = s.top() * val;
                    s.pop();
                    s.push( x );
                }
            }
        }
    }
    
    int sum = 0;
    while( !s.empty() )							// adding all elements of stack to get desired sum
    {
        sum = sum + s.top();
        s.pop();
    }
    return sum;
}

int main()
{
    string str;
    cout << "Enter the chemical formula" << endl;
    cin >> str;
    cout << "The mass of Molecule " << str << " is " << calmass(str) << endl;
}
    
