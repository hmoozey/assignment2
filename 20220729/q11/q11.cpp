
// File: q7.cpp
// Purpose: ………
// Author: Hamza.
// Section: S22
// ID: 20220729
// TA: Rana Abdelkader
// Date: 12 Oct 2023

#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <string>
#define endl '\n'
#define ll long long
using namespace std;

void check_c(ifstream &infile1, ifstream &infile2);
void check_w(ifstream &infile1, ifstream &infile2);

vector<string> getword(ifstream &infile);

void check_c(ifstream &infile1, ifstream &infile2)
{
    int n = 0;
    char c1, c2;
    string s1, s2;
    while (!infile1.eof())
    {
        c1 = infile1.get();
        s1.push_back(c1);
    }
    while (!infile2.eof())
    {
        c2 = infile2.get();
        s2.push_back(c2);
    }

    int MAX = max(s1.size(), s2.size());
    int MIN = min(s1.size(), s2.size());

    // cout << MAX << " " << MIN << endl;
    for (int i = 0; i < MIN - 1; i++)
    {
        // cout << s1[i] << " != " << s2[i] << endl;
        if (s1[i] != s2[i])
        {
            n++;
        }
    }
    if (n == 0)
    {
        cout << "file1 and file2 are identical" << endl;
    }
    else
    {
        cout << "file1 and file2 are identical expect for " << n + MAX - MIN << " characters..." << endl;
    }

    infile1.close();
    infile2.close();
}

void check_w(ifstream &infile1, ifstream &infile2)
{
    string word1 = "", word2, line;
    vector<string> s1, s2;
    s1 = getword(infile1);
    s2 = getword(infile2);
    //cout << s1.size() << endl;
    //cout << s2.size() << endl;
    int MAX = max(s1.size(), s2.size());
    int MIN = min(s1.size(), s2.size());
    int x = 0;
    for (int i = 0; i < MIN; i++)
    {
        if (s1[i] != s2[i])
        {
            word1 = s1[i];
            word2 = s2[i];
            x = i;
            break;
        }
    }
    if (word1.empty() && s1.size() == s2.size())
    {
        cout << "They are identical" << endl;
    }
    else if (s1.size() != s2.size())
    {
        cout << "The word is " << word1 << endl;
        cout << "the line ("; 
        for (int i = s1.size() - 4; i < s1.size(); i++)
        {
            cout << s1[i] << " " ;
        }
        cout << ")" << endl;
        cout << "the second line ("; 
        for (int i = s2.size() - 4; i < s2.size(); i++)
        {
            cout << s2[i] << " " ;
        }
        cout << ")";
    }
    else
    {
        cout << "The word is " << word1 << endl;
        cout << "the line (";
        for (int i = s1.size() - 4; i < s1.size(); i++)
        {
            cout << s1[i] << " " ;
        }
        cout << ")" << endl;
        cout << "the second line ("; 
        for (int i = s2.size() - 4; i < s2.size(); i++)
        {
            cout << s2[i] << " " ;
        }
        cout << ")";
    }

    infile1.close();
    infile2.close();
}
vector<string> getword(ifstream &infile)
{
    string word;
    vector<string> s;
    while (infile >> word)
    {
        s.push_back(word);
    }
    return s;
}

int main()
{
    int ch;
    string file1, file2;
    cout << "Enter the first file name : ";
    cin >> file1;
    ifstream infile1(file1);
    cout << "Enter the second file name : ";
    cin >> file2;
    ifstream infile2(file2);
    cout << "Do want compare them by words or characters ?" << endl;
    cout << "1 - characters" << endl;
    cout << "2 - words" << endl;
    cout << "Choose a number : ";
    cin >> ch;
    if (ch == 1)
    {
        check_c(infile1, infile2);
    }
    else if (ch == 2)
    {
        check_w(infile1, infile2);
    }
}