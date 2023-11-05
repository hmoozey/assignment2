
// File: q9.cpp
// Purpose: ………
// Author: Hamza.
// Section: S22
// ID: 20220729
// TA: Rana Abdelkader
// Date: 12 Oct 2023

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#define endl '\n'
#define ll long long
using namespace std;

bool tf = 0;

bool bears(int x)
{
    cout << " this x = " << x << endl;
    if (x == 42)
    {
        return 1;
    }

    if (x % 2 == 0)
    {
        //cout << " 1 " << endl;
        if (x / 2 > 42 && bears(x / 2) == 1)
        {
            return 1;
        }
    }

    if (((x % 4) == 0 || (x % 3) == 0))
    {
        //cout << " 2 " << endl;
        if (x - ((x % 10) * ((x % 100) / 10)) >= 42 && bears(x - ((x % 10) * ((x % 100) / 10))) == 1)
        {
            return 1;
        }
    }

    if (x % 5 == 0)
    {
        //cout << " 3 " << endl;
        if (x - 42 > 42 && bears(x - 42) == 1)
        {
            return 1;
        }
    }
    if (x == 42)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int g;
    cin >> g;
    cout << bears(g);
}