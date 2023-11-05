
// File: q7.cpp
// Purpose: ………
// Author: Hamza.
// Section: S22
// ID: 20220729
// TA: Rana Abdelkader
// Date: 12 Oct 2023

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#define endl '\n'
#define ll long long
using namespace std;

struct dominoT
{
    int leftDots;
    int rightDots;
};

bool FormsDominoChain(vector<dominoT> &dominos);

bool ct;

bool FormsDominoChain(vector<dominoT> &dominos)
{
    vector<dominoT> dom1;
    if (dominos.size() == 1 || dominos.size() == 0)
    {
        return 1;
    }
    else
    {
        for (int i = 0; i < dominos.size(); i++)
        {
            dominoT R, L, M;
            for (int j = 0; j < dominos.size(); j++)
            {
                for (int k = 0; k < dominos.size(); k++)
                {
                    if (dominos.size() > 3)
                    {
                        if (dominos[i].rightDots == dominos[j].leftDots && dominos[j].rightDots == dominos[k].leftDots && i != k && k != j && i != j)
                        {
                            vector<int> a = {i, j, k};
                            dom1 = dominos;
                            sort(a.begin(), a.end());
                            L = dominos[i];
                            M = dominos[j];
                            R = dominos[k];
                            dominos.push_back({dominos[i].leftDots, dominos[k].rightDots});

                            dominos.erase(dominos.begin() + a[2]);
                            dominos.erase(dominos.begin() + a[1]);
                            dominos.erase(dominos.begin() + a[0]);
                            if (FormsDominoChain(dominos))
                            {
                                return 1;
                            }
                            else
                            {
                                dominos = dom1;
                                //cout << " 2 domins size = " << dominos.size() << endl;
                            }
                        }
                    }
                    else if (dominos.size() == 3)
                    {
                        if (dominos[i].rightDots == dominos[j].leftDots && dominos[j].rightDots == dominos[k].leftDots && i != k && k != j && i != j)
                        {
                            return 1;
                        }
                    }
                    else if (dominos.size() == 2)
                    {
                        if (dominos[0].leftDots == dominos[1].rightDots || dominos[1].leftDots == dominos[0].rightDots)
                        {
                            return 1;
                        }
                    }
                }
            }
        }
    }
    return 0;
}

int main()
{
    int nd;
    cin >> nd;
    vector<dominoT> dom(nd);
    for (int i = 0; i < nd; i++)
    {
        cin >> dom[i].leftDots >> dom[i].rightDots;
    }
    if (FormsDominoChain(dom) == 1)
        cout << "true";
    else
        cout << "false";
}
