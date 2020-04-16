//
// Created by 0864h on 2020-04-16.
//
#include<iostream>
#include<algorithm>
using namespace std;
int d[1001][1001];
int main()
{
    int n, m;
    cin>>n>>m;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin>>d[i][j];
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            d[i][j] += max({d[i-1][j], d[i-1][j-1], d[i][j-1]});
        }
    }
    cout<<d[n][m];
}