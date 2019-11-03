// convert infix notation to reverse polish notation

#include <iostream>
#include<stack>
#include<string>
using namespace std;


int precedence(char a, char b)				// functio will return 1 if a has higher precedence than b
{
    if( a=='/')
    return 1;
    if(a=='*' && b != '/')
    return 1;
    if(a=='+' && b!= '/' && b!='*')
    return 1;
    if(a=='-' && b== '(')
    return 1;
    return 0;
}

string convert_notation( string inp )			// function will return reverse polish notation
{
    string output = "";
    int j = 0;
    stack<char>s;
    for( int i = 0; i < inp.length(); i++ )
    {
        if( inp[ i ] >= 97 && inp[ i ] <= 122 )			// if alphabet is found append it in result string 
        {
            output.append( 1, inp[ i ] );
        }
        else
        {
            if( inp[ i ] != ')' )				// pop until a element of lower precedence is found
            {
                while( !s.empty() && precedence( s.top(), inp[ i ] ) == 1 )
                {
                    output.append( 1, s.top() );
                    s.pop();
                }
                s.push( inp[ i ] );				// adding the operator
            }
            else
            {
                if( inp[ i ]== '(' )				// adding '('
                {
                    s.push( inp[ i ] );
                }
                else
                if( inp[ i ] == ')' )				// if ')' is found pop until '(' is found and all those elements in result
                {
                    while( s.top() != '(' )
                    {
                        output.append( 1, s.top() );
                        s.pop();
                    }
                    s.pop();
                }
            }
        }
    }
    while( !s.empty() )
    {
    output.append( 1, s.top() );
    s.pop();
    }
    return output;
}

int main()
{
    string inp;
    cout << "Enter the infix notation" << endl;
    cin >> inp;
    string output = convert_notation( inp );
    cout << "The reverse polish notation is ";
    cout << output << endl;
    return 0;
}
