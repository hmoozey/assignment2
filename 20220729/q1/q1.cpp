
// File: q1.cpp
// Purpose: ………
// Author: Hamza.
// Section: S22
// ID: 20220729
// TA: Rana Abdelkader
// Date: 12 Oct 2023

#include <iostream>
#include <vector>
#include <string>
#define endl '\n'
#define ll long long
#define fast ios_base::sync_with_stdio;cin.tie(0);cout.tie(0);
using namespace std;
int main()
{
    fast;
    char sen[100];
    cin.getline(sen,100);
    string sen1;
    for (int i = 0; i < 100; i++)
    {
        if(sen[i] == ' ' && sen[i - 1] == ' ')
        {
            continue;
        }
        else if(sen[i] >= 'A' && sen[i] <= 'Z')
        { 
            sen1.push_back(sen[i] + 32);
        }
        else
        {
            sen1.push_back(sen[i]);
        }
    }
    cout << sen1;
}