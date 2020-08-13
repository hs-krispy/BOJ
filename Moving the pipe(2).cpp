//
// Created by 0864h on 2020-08-13.
//
#include<iostream>
using namespace std;
int N, house[33][33];
long long d[33][33][3];
int main()
{
    cin >> N;
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
            cin >> house[i][j];
    }
    d[1][2][0] = 1;
    for(int i = 1; i <= N; i++)
    {
        for(int j = 3; j <= N; j++)
        {
            if(house[i][j] == 1) continue;
            d[i][j][0] = d[i][j - 1][0] + d[i][j - 1][1];
            if(house[i - 1][j] == 0 && house[i][j - 1] == 0)
                d[i][j][1] = d[i - 1][j - 1][0] + d[i - 1][j - 1][1] + d[i - 1][j - 1][2];
            d[i][j][2] = d[i - 1][j][1] + d[i - 1][j][2];
        }
    }
    cout << d[N][N][0] + d[N][N][1] + d[N][N][2];
}
