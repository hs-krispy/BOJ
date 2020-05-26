//
// Created by 0864h on 2020-05-27.
//
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int n, d[100001];
    cin >> n;
    d[0] = 0; d[1] = 1; d[2] = 2; d[3] = 3;
    for(int i = 4; i <= n; i++)
    {
        d[i] = i;
        for(int j = 1; j <= int(sqrt(i)); j++)
        {
            d[i] = min(d[i], d[i - j * j] + 1);
        }
    }
    cout << d[n];
}
