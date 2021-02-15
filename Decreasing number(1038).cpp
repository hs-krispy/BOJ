//
// Created by 0864h on 2021-01-23.
//
#include<iostream>
#include<map>
using namespace std;
int N, count = -1;
map<long long, bool> check;
void number(string s, int cmp)
{
    for(int i = 0; i < cmp; i++)
    {
        if(!check[stoll(s + to_string(i))])
        {
            count++;
            check.insert({stoll(s + to_string(i)), true});
            number(s + to_string(i), i);
        }
    }
}
int main()
{
    cin >> N;
    if(N <= 10)
    {
        cout << N;
        return 0;
    }
    for(int i = 0; i <= 10; i++)
    {
        check.insert({i, true});
        count++;
    }
    for(int i = 2; i <= 9; i++)
        number(to_string(i), i);
    int c = -1;
    for(auto iter = check.begin(); iter != check.end(); ++iter)
    {
        c++;
        if(c == N)
        {
            cout << iter -> first;
            return 0;
        }
    }
    cout << -1;
}
