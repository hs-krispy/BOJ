//
// Created by 0864h on 2020-05-26.
//
#include<iostream>
using namespace std;
int main()
{
    int n;
    long long d[91][2];
    d[1][0] = 1; d[1][1] = 0; d[2][1] = 0; d[2][0] = 1;
    cin >> n;
    for(int i = 3; i <= n; i++)
    {
        d[i][0] = d[i - 1][0] + d[i - 1][1];
        d[i][1] = d[i - 1][0];
    }
    cout << d[n][0] + d[n][1];
}
