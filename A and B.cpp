//
// Created by 0864h on 2020-08-17.
//
#include<iostream>
#include <algorithm>
using namespace std;
string S, T;
bool check = false;
void game(string s, int c)
{
    if(check)
        return;
    if(c == S.length())
    {
        if(s == S)
        {
            check = true;
            cout << 1;
            return;
        }
    }
    if(s[s.length() - 1] == 'A')
        game(s.substr(0, s.length() - 1), c - 1);
    if(s[s.length() - 1] == 'B')
    {
        string temp = s.substr(0, s.length() - 1);
        reverse(temp.begin(), temp.end());
        game(temp, c - 1);
    }
}
int main()
{
    cin >> S >> T;
    game(T, T.length());
    if(!check)
        cout << 0;
}