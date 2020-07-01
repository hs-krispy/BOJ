//
// Created by 0864h on 2020-06-05.
//
#include<iostream>
#include<climits>
using namespace std;
char ie[10];
int k;
long long Max = 0, Min = LONG_LONG_MAX;
string ans1, ans2;
bool check[10];
void max_min(int c, string s, int cmp)
{
    if(c == k + 1)
    {
        if(Max < atoll(s.c_str()))
        {
            Max = atoll(s.c_str());
            ans1 = s;
        }
        if(Min > atoll(s.c_str()))
        {
            Min = atoll(s.c_str());
            ans2 = s;
        }
        return;
    }
    string temp = s;
    for(int i = 0; i < 10; i++)
    {
        if(s == "" && !check[i])
        {
            s += to_string(i);
            check[i] = true;
            max_min(c, s, i);
            check[i] = false;
            s = temp;
        }
        if(s != "" && ie[c] == '<' && !check[i] && cmp < i)
        {
            s += to_string(i);
            check[i] = true;
            max_min(c + 1, s, i);
            check[i] = false;
            s = temp;
        }
        else if(s != "" && ie[c] == '>' && !check[i] && cmp > i)
        {
            s += to_string(i);
            check[i] = true;
            max_min(c + 1, s, i);
            check[i] = false;
            s = temp;
        }
    }
}
int main()
{
    cin >> k;
    for(int i = 1; i <= k; i++)
        cin >> ie[i];
    max_min(1, "", 0);
    cout << ans1 << "\n" << ans2;
}
