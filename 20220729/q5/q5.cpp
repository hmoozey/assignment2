
// File: q5.cpp
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

int main()
{
    priority_queue<pair<ll, string>> we, wei;
    string menu;
    do
    {
        cout << "a - add player" << endl;
        cout << "b - print top 10" << endl;
        cout << "c - check player" << endl;
        cout << "d - exit" << endl;
        cout << "Enter a letter : ";
        cin >> menu;
        if (menu == "a")
        {
            ll score;
            string name;
            cout << "Enter a name : ";
            cin >> name;
            cout << "Enter the score : ";
            cin >> score;
            we.push({score, name});
            if (we.size() > 10)
            {
                for (int i = 0; i < s; i++)
                {
                    wei.push({-we.top().first, we.top().second});
                    we.pop();
                }
                wei.pop();
                for (int i = 0; i < s; i++)
                {
                    we.push({-wei.top().first, wei.top().second});
                    wei.pop();
                }
            }
        }
        else if (menu == "b")
        {
            int s;
            cout << "TOP 10 ARE : " << endl;
            for (int i = 0; i < s; i++)
            {
                cout << "name : " << we.top().second << " | score : " << we.top().first << endl;
                wei.push({-we.top().first, we.top().second});
                we.pop();
            }
            for (int i = 0; i < s; i++)
            {
                we.push({-wei.top().first, wei.top().second});
                wei.pop();
            }
        }
        else if (menu == "c")
        {
            int s, a = 0;
            if (we.size() > 10)
            {
                s = 10;
            }
            else
            {
                s = we.size();
            }
            bool c = 1;
            string nc;
            cout << "Enter the name : ";
            cin >> nc;
            for (int i = 0; i < s; i++)
            {
                if (nc == we.top().second && c == true)
                {
                    a = we.top().first;
                    c = 0;
                }
                wei.push({-we.top().first, we.top().second});
                we.pop();
            }
            if (c == 0)
            {
                cout << nc << " Highest score is " << a << endl;
            }
            else
            {
                cout << nc << " is not in the TOP 10" << endl;
            }
            for (int i = 0; i < s; i++)
            {
                we.push({-wei.top().first, wei.top().second});
                wei.pop();
            }
        }
    } while (menu != "d");
}