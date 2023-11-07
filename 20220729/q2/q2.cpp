
// File: q2.cpp
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
using namespace std;
int main()
{
    string s1,s2;
    getline(cin, s1);
    vector<string> sen;

    for (int i = 0; i < s1.size(); i++)
    {
        if(s1[i] == ' ')
        {
            sen.push_back(s2);
            s2 = "";
        }
        else
        {
            s2.push_back(s1[i]);
        }
        if(i == s1.size() - 1)
        {
            sen.push_back(s2);
        }
    }

    for (int i = 0; i < sen.size(); i++)
    {
        if (sen[i] == "He" || sen[i] == "She")
        {
            sen.push_back("He or she");
        }
        else if (sen[i] == "he" || sen[i] == "she")
        {
            sen.push_back("he or she");
        }
        else if (sen[i] == "he." || sen[i] == "she.")
        {
            sen.push_back("he or she.");
        }
        else if (sen[i] == "Him" || sen[i] == "Her")
        {
            sen.push_back("Him or her");
        }
        else if (sen[i] == "him" || sen[i] == "her")
        {
            sen.push_back("him or her");
        }
        else if (sen[i] == "him." || sen[i] == "her.")
        {
            sen.push_back("him or her.");
        }
        else if (sen[i] == "Himself" || sen[i] == "Herself")
        {
            sen.push_back("Himself or herself");
        }
        else if (sen[i] == "himself" || sen[i] == "herself")
        {
            sen.push_back("himself or herself");
        }
        else if (sen[i] == "himself." || sen[i] == "herself.")
        {
            sen.push_back("himself or herself.");
        }
        else if (sen[i] == "His" || sen[i] == "Hers")
        {
            sen.push_back("His or hers");
        }
        else if (sen[i] == "his" || sen[i] == "hers")
        {
            sen.push_back("his or hers");
        }
        else if (sen[i] == "his." || sen[i] == "hers.")
        {
            sen.push_back("his or hers.");
        }
    }

    for (int i = 0; i < sen.size(); i++)
    {
        cout << sen[i] << " ";
    }
}
