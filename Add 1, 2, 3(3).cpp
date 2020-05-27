//
// Created by 0864h on 2020-05-28.
//
#include<iostream>
using namespace std;
const int mod = 1000000009;
long long d[1000001];
int main()
{
    int t, n;
    d[1] = 1; d[2] = 2; d[3] = 4;
    for(int i = 4; i <= 1000000; i++)
    {
        d[i] = d[i - 1] + d[i - 2] + d[i - 3];
        d[i] %= mod;
    }
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        cin >> n;
        cout << d[n] << "\n";
    }
}
