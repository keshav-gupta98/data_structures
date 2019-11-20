#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
int func(int n, int arr[])
{
    int curr = 1;
    stack<int> a;
    stack<int> b;
    int i = 0;
    while(curr<=n)
    {
        if(i<n&&arr[i]==curr)
        {
            curr++;
            i++;
            a.push(curr);
        }
        else if(!b.empty()&&b.top()==curr)
        {
            a.push(b.top());
            b.pop();
            curr++;
        }
        else if(i<n&&arr[i]!=curr&&!b.empty()&&arr[i]!=b.top())
        {
            if(arr[i]>b.top())
            {
                cout << "no" << endl;
                return 0;
            }
            b.push(arr[i]);
            i++;
        }
        else if(i<n&&arr[i]!=curr&&b.empty())
        {
            b.push(arr[i]);
            i++;
        }
    }
    cout << "yes" << endl;
    return 0;
}
int main() {
    int n; // no of trucks
    while(true)
    {
        cin >> n;
        if(n==0)
        return 0;
        int arr[n];
        for( int i = 0 ; i< n ;i++)
        {
            cin >> arr[i];
        }
        func(n,arr);
    }
    return 0;
}