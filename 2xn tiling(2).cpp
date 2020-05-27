//
// Created by 0864h on 2020-05-28.
//
#include<iostream>
using namespace std;
int main()
{
    int n, d[1001];
    d[1] = 1; d[2] = 3;
    cin >> n;
    for(int i = 3; i <= n; i++)
    {
        d[i] = d[i - 1] + 2 * d[i - 2];
        d[i] %= 10007;
    }
    cout << d[n];
}
