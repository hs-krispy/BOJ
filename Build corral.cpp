//
// Created by 0864h on 2021-02-26.
//
#include<iostream>
#include<algorithm>
using namespace std;
int M, N, field[1001][1001], d[1001][1001], Max = 0;
int main()
{
    cin >> M >> N;
    for(int i = 1; i <= M; i++)
    {
        for(int j = 1; j <= N; j++)
            cin >> field[i][j];
    }
    for(int i = 1; i <= M; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            if(field[i][j] == 0)
            {
                d[i][j] = min({d[i - 1][j], d[i][j - 1], d[i - 1][j - 1]}) + 1;
                if(Max < d[i][j])
                    Max = d[i][j];
            }
        }
    }
    cout << Max;
}
