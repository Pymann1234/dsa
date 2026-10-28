#include <iostream>
#include <stack>
#include <sstream>
#include <string>

using namespace std;

int forLoop(int n)
{
    int res = 0;
    for (int i = 1; i <= n; ++i)
    {
        res += i;
    }
    return res;
}

int whileLoop(int n)
{
    int res = 0;
    int i = 1;
    while (i <= n)
    {
        res += i;
        i++;
    }
    return res;
}

// whileloop(two updates)
int whileLoopII(int n)
{
    int res = 0;
    int i = 1; // Initializeconditionvariable
    // Sum 1, 4, 10, ...
    while (i <= n)
    {
        res += i;
        // Update condition variable
        i++;
        i *= 2;
    }
    return res;
}

string nestedForLoop(int n)
{
    ostringstream res;
    //  Loop i = 1, 2, ..., n-1, n
    for (int i = 1; i <= n; ++i)
    {
        // Loop j = 1, 2, ..., n-1, n
        for (int j = 1; j <= n; ++j)
        {
            res << "(" << i << ", " << j << "), ";
        }
    }
    return res.str();
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    string res = nestedForLoop(n);
    cout << "Result: " << res << endl;
}
