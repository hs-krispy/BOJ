//
// Created by 0864h on 2020-06-28.
//
#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
string cc;
int ans = INT_MAX, n, button, idx, d;
bool check[10];
void count(string c, int digit)
{
    if(!(d == 1 && digit == 1) && (digit == d || digit == d + 1 || digit == d + 2))
    {
        ans = min({ans, abs(100 - atoi(cc.c_str())), abs(atoi(cc.c_str()) - atoi(c.c_str())) + digit - 1});
        if(digit == d + 2)
            return;
    }
    string temp = c;
    for(int i = 0; i < 10; i++)
    {
        if(!check[i])
        {
            idx = i;
            c += to_string(idx);
            count(c, digit + 1);
            c = temp;
        }
    }
}
int main()
{
    cin >> cc >> n;
    for(char c : cc)
        d++;
    for(int i = 0; i < n; i++)
    {
        cin >> button;
        check[button] = true;
    }
    count("", 1);
    if(ans == INT_MAX)
        ans = abs(100 - atoi(cc.c_str()));
    cout << ans;
}
