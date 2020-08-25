//
// Created by salmon11 on 2020-08-25.
//
#include<iostream>
#include<stack>
using namespace std;
int T;
int main()
{
    cin >> T;
    for(int i = 0; i < T; i++)
    {
        string str;
        stack<char> s;
        cin >> str;
        for(int j = 0; j < str.length(); j++)
        {
            if(s.empty())
                s.push(str[j]);
            else
            {
                if(s.top() == '(' && str[j] == ')')
                {
                    s.pop();
                    continue;
                }
                s.push(str[j]);
            }
        }
        if(!s.empty())
            cout << "NO" << "\n";
        else cout << "YES" << "\n";
    }
}
