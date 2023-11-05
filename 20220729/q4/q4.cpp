
// File: q4.cpp
// Purpose: ………
// Author: Hamza.
// Section: S22
// ID: 20220729
// TA: Rana Abdelkader
// Date: 12 Oct 2023

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
#define endl '\n'
#define ll long long
using namespace std;
int main()
{
    set<int> prime;
    vector<int> pr;
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        prime.insert(i);
    }
    for (int i = 2; i <= n; i++)
    {
        for (auto itr = prime.begin(); itr != prime.end(); itr++)
        {
            cout << *itr << " % " << i << endl;
            if (*itr % i == 0 && i != *itr)
            {
                pr.push_back(*itr);
            }
        }
        for (int j = 0; j < pr.size(); j++)
        {
            prime.erase(pr[j]);
        }
    }
    for (auto itr = prime.begin(); itr != prime.end(); itr++)
    {
        cout << *itr << " ";
    }
}